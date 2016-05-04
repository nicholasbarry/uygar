%% notes
%{
sbatch --gres=gpu:1 --mem=128000 -n 1 -c 20 script args
* imgFilePath, unitTest must be set before this script is run
* should be run from same directory as image file
* will create a new directory in place in which all files are saved out
* take care that all functions must be on the current path

* when this script concludes, inspect the image and build manipulationSets
accordingly. then run superVoxelize2 from the new directory, as it will
look for variables saved out from this session.

* repeat the inspect->manipulate loop to taste

%}

%% initialization

% path manipulation
[~,imgFilename,~]                                        = fileparts(imgFilePath);
dirname                                                  = [imgFilename,'_','Segmentation'];
mkdir(dirname);

% specify run parameters
CHANNELCOUNT                                             = 3;               % eg, R,G,B can this be extracted programmatically? eg, info.PhotometricInterpretation == 'RGB'
sigma                                                    = 2000;

superVoxelOpts.HMINTH26                                  = 0.008;           %increasing this may speed up runtime, eg 0.01
superVoxelOpts.spatialDistanceCalculationOpts.upperBound = 2;              % orig at 31, try 10-15, big impact on runtime
superVoxelOpts.colorDistanceUpperBound                   = 0.03;

superVoxelOpts.splitHardSVopts.detThreshold              = 10e-10;%5e-11;           % increasing to maybe 10e-10, for initial checks (runtime). controls homogeneity of svoxels
superVoxelOpts.splitHardSVopts.connectivity              = 26;
superVoxelOpts.splitHardSVopts.subdivisionSizeThreshold  = 2;

superVoxelOpts.removeSmallComponents.minVoxelCount       = 20;              % 100
superVoxelOpts.removeSmallComponents.moiRatioThreshold   = 3;
superVoxelOpts.removeSmallComponents.zAnisotropy         = 3;

maxIter                                                  = 200;             % number of iterations clustering should go through
clusterCount                                             = 20;              % initial guess as to how many neurons are in the volume

if unitTest                                                                 % if testing code
        cutoff                                          = 12;               % number of slices to go through for testing purposes
        superVoxelOpts.splitHardSVopts.detThreshold     = 10e-10;
        superVoxelOpts.spatialDistanceCalculationOpts.upperBound = 10;
        superVoxelOpts.HMINTH26                         = 0.01;
end

graphData.opts_irbleigs.K = 20;
graphData.c1 = 2e-4;
graphData.c2 = 1e-3;
graphData.c2sf = 0;
graphData.nC = 0.1;
graphData.s1 = 0.4;
graphData.s2 = 1;
graphData.sig = 0;

% save run parameters
save([dirname,'/runParameters.mat'],'CHANNELCOUNT','sigma','superVoxelOpts','maxIter','unitTest','graphData','-v7.3')


%% housekeeping

start = datetime;

% img data
info         = imfinfo(imgFilePath);
numXpixels   = info(1).Width;
numYpixels   = info(1).Height;
stackHeight  = numel(info); 
if unitTest;stackHeight=cutoff;end;                                         % unit test
numSlices    = stackHeight/CHANNELCOUNT;

% ingest img
thisVol          = zeros(numYpixels, numXpixels, stackHeight);
fprintf('\nReading in image...');tic
parfor i = 1:stackHeight;
  thisVol(:,:,i) = imread(imgFilePath,'Index',i);
end
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))


%% denoise

% simultaneously denoise images + separate channels out into bbvol's 4th dimension
% takes ~13700s = 3.8hrs
bbVol = zeros(numYpixels,numXpixels,numSlices,CHANNELCOUNT);
fprintf('\nDenoising...');tic
parfor i = 1:CHANNELCOUNT
    bbVol(:,:,:,i) = bm4d(squeeze(thisVol(:,:,i:CHANNELCOUNT:stackHeight)), 'Gauss', sigma); % bm4d not multithreaded but minimal parfor speedup "due to the way memory (cache in particular) is accessed" (per Foi)
end
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))
clear thisVol i;


% checkpoint
bbVolfilename = [dirname,'/',imgFilename,sprintf('_denoisedbm4d_colors%d_sigma%d.mat',CHANNELCOUNT,sigma)];
save(bbVolfilename, 'bbVol', '-v7.3')


%% supervoxelize


% flatten bbVol negatives to zero
bbVol(bbVol<0)=0;


% normalize each channel's intensity
fprintf('\nNormalizing each channel''s intensity...');tic
parfor i = 1:CHANNELCOUNT
    rawStack = bbVol(:,:,:,i);
    rawStack = rawStack - min(rawStack(:)); 
    rawStack = rawStack / max(rawStack(:)); 
    bbVol(:,:,:,i) = rawStack;
end
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))


% find the maximum intensity gradient of each point across all dimensions/colors
% can probably do this better with padarray, but it goes pretty fast as-is
fprintf('\nCalculating intensity gradient...');tic
gradAmplitude = zeros(numYpixels, numXpixels, numSlices);

tmpbb = cat(1,bbVol(1,:,:,:),bbVol);
gradAmplitude = max(gradAmplitude, squeeze(max(abs(diff(tmpbb,1,1)),[],4)) );

tmpbb = cat(2,bbVol(:,1,:,:),bbVol);
gradAmplitude = max(gradAmplitude, squeeze(max(abs(diff(tmpbb,1,2)),[],4)) );

tmpbb = cat(3,bbVol(:,:,1,:),bbVol);
gradAmplitude = max(gradAmplitude, squeeze(max(abs(diff(tmpbb,1,3)),[],4)) );

clear tmpbb;
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))


% 26-WATERSHED SEGMENTATION, 0 DENOTES WATERSHED BOUNDARIES, 1 DENOTES BACKGROUND OBJECT
% takes ~6min on 1 node
fprintf('\nDetecting and removing the background...');tic
L = watershed(imhmin(gradAmplitude, superVoxelOpts.HMINTH26), 26);
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))
clear gradAmplitude;

stackSize = size(L);
numVoxels = prod(stackSize);

fprintf('\nAssigning watershed boundaries to objects...');tic % takes ~6000s = 1.66 hr on 1 node
L = assign6Boundaries(L, bbVol);
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))

% checkpoint
filename = [dirname,'/',imgFilename,'_L.mat'];
fprintf('\nSaving L...\n\n')
save(filename, 'L', '-v7.3')


fprintf('\nRemoving small components...');tic % takes ~13860s = 3.8hrs on 1 node
mask = removeSmallComponents(L~=1, superVoxelOpts.removeSmallComponents);
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))
save([dirname,'/',imgFilename,'_mask.mat'],'mask','-v7.3')

fprintf('\nCompacting...');tic
L(~mask) = 1;                                                               % 1 IS ASSIGNED TO BACKGROUND IN THIS DATASET - SHOULD REVISE FOR GENERAL CASE?
for i = max(L(:)):-1:2 % counting backwards by 1 from the highest value in L
    if ~any(L(:)==i) % if some i on the way down does not appear in L
        L(L>i) = L(L>i) - 1; % shift all the values of L higher than i down by 1
    end
end % this results in a compacted L: [1, 2, 5] => [1, 2, 3]
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))

% checkpoint 
filename = [dirname,'/',imgFilename,'_L.mat'];
fprintf('\nSaving L...\n\n')
save(filename, 'L', '-v7.3')
delete([dirname,'/',imgFilename,'_mask.mat']);

% store supervoxels 
% takes ~30min
superVoxelCells = cell(1,max(L(:))-1);                                      % 1 IS ASSIGNED TO BACKGROUND IN THIS DATASET - SHOULD REVISE FOR GENERAL CASE
fprintf('\nForming supervoxels...');tic
parfor i = 1:max(L(:))-1
    superVoxelCells{i} = find(L==i+1);                                      % (superVoxelCells is a cell array where each cell is a list of the linear indices of L where that cell's supervoxel has pixels)
end
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))

% checkpoint
save([dirname,'/',imgFilename,'_superVoxelCells.mat'],superVoxelCells,'-v7.3')

% split heterogeneous supervoxels
% takes about 14785s = 4.1hrs
fprintf('\nSplitting heterogeneous supervoxels...');tic
[L, superVoxelCells] = splitHardSuperVoxels(superVoxelOpts.splitHardSVopts, superVoxelCells, bbVol); 
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))

% checkpoint
save([dirname,'/',imgFilename,'_LsuperVoxelCells.mat'],superVoxelCells,'-v7.3')
delete([dirname,'/',imgFilename,'_superVoxelCells.mat'],[dirname,'/',imgFilename,'_L.mat'])

% get supervoxel means, boundaries
% takes ~6min
fprintf('\nCalculating supervoxel means and boundaries...');tic
cc                        = numel(superVoxelCells);
superVoxelMeans           = zeros(cc, CHANNELCOUNT);
boundaryVoxels            = cell(1, cc);
boundaryVoxelsSub         = cell(1, cc);

parfor kk = 1:cc
    [xx,yy,zz]            = ind2sub(stackSize, superVoxelCells{kk});        % (returns the xyz coordinates in the stack of all the pixels in the current supervoxel)
    xSub                  = min(xx)-2;
    ySub                  = min(yy)-2;
    zSub                  = min(zz)-2;
    xx                    = xx-xSub;
    yy                    = yy-ySub;
    zz                    = zz-zSub;
    maxxx                 = max(xx);
    maxyy                 = max(yy);
    maxzz                 = max(zz);
    tmp                   = false(maxxx+1, maxyy+1, maxzz+1);
    reducedIndices        = sub2ind([maxxx+1, maxyy+1, maxzz+1], xx, yy, zz);
    tmp(reducedIndices)   = true;
    localBoundaryVoxels   = find(tmp & ~imerode(tmp, ones(3,3,3)));
    
    if ~isempty(localBoundaryVoxels)
        [xx,yy,zz]        = ind2sub(size(tmp), localBoundaryVoxels);
    end
    
    xx                    = xx+xSub;
    yy                    = yy+ySub;
    zz                    = zz+zSub;
    boundaryVoxelsSub{kk} = [xx,yy,zz];
    boundaryVoxels{kk}    = sub2ind(stackSize, xx, yy, zz);
    
    thisSVcolors          = [];
    for dd = 1:CHANNELCOUNT
        thisSVcolors      = [thisSVcolors, bbVol(superVoxelCells{kk} + (dd-1)*numVoxels)];
    end
    superVoxelMeans(kk,:) = mean(thisSVcolors, 1);
end
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))


% checkpoint
filename = [dirname,'/',imgFilename,'_superVoxelBoundaries.mat'];
fprintf('\nSaving supervoxel boundaries...\n\n')
save(filename, 'cc', 'superVoxelOpts', 'superVoxelCells', 'superVoxelMeans', 'boundaryVoxelsSub', '-v7.3')


% get affinity graph
fprintf('\nCalculating supervoxel affinities...');tic
sAff = calculate_sAff(cc, boundaryVoxelsSub, superVoxelOpts.spatialDistanceCalculationOpts); 
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))

% generate square_sAff
[ii_sAff, ~, ss_sAff] = find(sAff);
yy = ceil( (2*cc-1 - sqrt((2*cc-1)^2-8*ii_sAff))/2 );
xx = ii_sAff - cc*yy + cc + yy.*(yy+1)/2;
square_sAff = sparse(xx, yy, ss_sAff, cc, cc);
square_sAff = square_sAff + transpose(square_sAff); % send to stefanie
clear ii_sAff; clear ss_sAff; clear xx; clear yy;


% checkpoint
filename = [dirname,'/',imgFilename,'_superVoxelAffinities.mat'];
fprintf('\nSaving supervoxel affinities...\n\n')
save(filename, 'sAff','cc', 'boundaryVoxelsSub', 'superVoxelOpts', '-v7.3');


% initial clustering
fprintf('\nClustering...');tic
voxelCounts                     = cellfun(@length,superVoxelCells)';

opts_fkmeans.weight             = sqrt(voxelCounts);
opts_fkmeans.careful            = true;
opts_fkmeans.maxIter            = maxIter;

if CHANNELCOUNT == 3
    superVoxelMeansLUV          = rgb2luv(superVoxelMeans')'; % send these two to stefanie
else
	superVoxelMeansLUV(:,1:3)   = rgb2luv(superVoxelMeans(:,1:3)')';
    superVoxelMeansLUV(:,4:end) = superVoxelMeans(:,4:end)*50;
end

index                           = snrAwareKmeans(superVoxelMeansLUV, clusterCount, opts_fkmeans);
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))
% checkpoint
save([dirname,'/',imgFilename,'_clustering.mat'],'superVoxelMeansLUV','index','-v7.3');
save([dirname,'/',imgFilename,'_ForStefanie.mat'],'superVoxelMeansLUV','superVoxelMeans','square_sAff');

%% human interaction
%{ 
segprojection here
human chooses which through manipulateClusters which spits back out the
index (which may have entries <1 in it)
which is then fed into calculateNormalizedCuts_mem through the following
code:

(if you like segprojection enough after snrKmeans, you can stop there.
essentially, calculateNormalizedCuts_mem is a way of refining the color
segmentation and takes as input human decisions that reduce the Nk landscape
it has to search through)
%}

segprojectionWrite
save([dirname,'/',imgFilename,'_forManipulation.mat'],'index','graphData','opts_fkmeans','superVoxelMeansLUV','square_sAff','voxelCounts','stackSize','superVoxelCells','numXpixels','numYpixels','-V7.3');
delete(pool)
exit

% human looks at collage of 2D supervoxel projections in the image generated 
% in segProjectionWrite and specifies which to split/merge/delete/etc via
% manipulationSets

% %% superVoxelize2.m (replace old file contents)
% 
% % pass it imgFilePath to set up / save out properly
% % pass it manipulationSets to manipulateClusters
% % repeat this script until satisfied
% 
% [~,imgFilename,~]                                        = fileparts(imgFilePath);
% dirname                                                  = [imgFilename,'_','Segmentation'];
% load([dirname,'/',imgFilename,'_forManipulation.mat']);
% 
% fprintf('\nManipulating supervoxels...');tic
% indexUI = manipulateClusters(index, manipulationSets, superVoxelMeansLUV, opts_fkmeans);
% fprintf(' done in %f seconds.\n\n',toc)
% 
% segprojectionWrite
% 
% if ~strcmp(java.lang.System.getProperty('java.awt.headless'),'true')
%     imshow(jpgFilepath);
% end
% 
% save([dirname,'/',imgFilename,'_forGraphCuts.mat'],'-V7.3');


% %% superVoxelize3.m
% %{
% % pass it imgFilePath to set up / save out properly
% 
% %}
% [~,imgFilename,~]                                        = fileparts(imgFilePath);
% dirname                                                  = [imgFilename,'_','Segmentation'];
% load([dirname,'/',imgFilename,'_forGraphCuts.mat']);
% start = datetime;
% for kk = 1:max(indexUI)
%   seedSets{kk} = find(indexUI==kk);
% end
% 
% % calculateNormalizedCuts_mem
% graphData.seedSets = seedSets;
% graphData.ccIDsOfSVs = indexUI;
% graphData.colorData          = superVoxelMeansLUV;
% graphData.square_sAff        = square_sAff;
% graphData.svSizes            = voxelCounts;
% graphData.stackSize          = stackSize;
% graphData.minClumpCount      = 0.005 * cc / graphData.opts_irbleigs.K;
% graphData.minSVcountFraction = 0.1 / graphData.opts_irbleigs.K;
% 
% fprintf('\nCalculating normalized cuts...');tic
% [index, scoreInf, score1]    = calculateNormalizedCuts_mem(graphData);
% fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))
% 
% % inspect
% segProjectionWrite
% 
% % checkpoint
% save([dirname,'/',imgFilename,'_normCuts.mat'],'index','-v7.3');

%% visualization

fprintf('\nVisualizing supervoxels...');tic
segProjectionWrite
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))

%% finish up
save([dirname 'varsForRunUygar2.mat'],'index','stackSize','superVoxelCells','numXpixels','numYpixels','dirname','imgFilename','superVoxelMeansLUV', 'opts_fkmeans','graphData','square_sAff','voxelCounts')
