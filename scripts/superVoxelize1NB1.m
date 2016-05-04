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

%{
* bm4d is hopelessly single-threaded and b/c it's in a binary, can't view
* TO DO in removesmallcomponents
    - ind2sub outside parfor?
    - profile to look for bottlenecks ? why 4 hrs?
    - why did this STOP taking 4 hrs?
* 
%}

%% initialization
profile on;

% path manipulation
[~,imgFilename,~]                                        = fileparts(imgFilePath);
dirname                                                  = [imgFilename,'_','Segmentation'];
if unitTest;dirname=[dirname,'_unitTest'];end;

if exist([dirname,'/',imgFilename,'_1_runParameters.mat'],'file')
    load([dirname,'/',imgFilename,'_1_runParameters.mat'])
    start = datetime;
else
    % specify run parameters
    CHANNELCOUNT                                             = 3;               % eg, R,G,B can this be extracted programmatically? eg, info.PhotometricInterpretation == 'RGB'
    sigma                                                    = 2000;

    superVoxelOpts.HMINTH26                                  = 0.01;           %increasing this may speed up runtime, eg 0.01
    superVoxelOpts.spatialDistanceCalculationOpts.upperBound = 31;              % orig at 31, try 10-15, big impact on runtime
    superVoxelOpts.colorDistanceUpperBound                   = 0.03;

    superVoxelOpts.splitHardSVopts.detThreshold              = 5e-11;           % increasing to maybe 10e-10, for initial checks (runtime). controls homogeneity of svoxels
    superVoxelOpts.splitHardSVopts.connectivity              = 26;
    superVoxelOpts.splitHardSVopts.subdivisionSizeThreshold  = 2; %50;

    superVoxelOpts.removeSmallComponents.minVoxelCount       = 100;              % 100 (test)
    superVoxelOpts.removeSmallComponents.moiRatioThreshold   = 3;
    superVoxelOpts.removeSmallComponents.zAnisotropy         = 3;
    superVoxelOpts.removeSmallComponents.precise             = 1;

    maxIter                                                  = 200;             % number of iterations clustering should go through
    clusterCount                                             = 20;              % initial guess as to how many neurons are in the volume


    if unitTest                                                                 % if testing code
        cutoff                                               = 24;               % number of slices to go through for testing purposes
        superVoxelOpts.splitHardSVopts.detThreshold          = 10e-10;
        superVoxelOpts.spatialDistanceCalculationOpts.upperBound = 10;
        superVoxelOpts.HMINTH26                              = 0.01;
        superVoxelOpts.removeSmallComponents.precise         = 0;
    end

    graphData.opts_irbleigs.K = 20;
    graphData.c1 = 2e-4;
    graphData.c2 = 1e-3;
    graphData.c2sf = 0;
    graphData.nC = 0.1;
    graphData.s1 = 0.4;
    graphData.s2 = 1;
    graphData.sig = 0;


    %% housekeeping

    start         = datetime;

    % img data
    info          = imfinfo(imgFilePath);
    numXpixels    = info(1).Width;
    numYpixels    = info(1).Height;
    stackHeight   = numel(info); 
    if unitTest;stackHeight=cutoff;end;                                         % unit test
    numSlices     = stackHeight/CHANNELCOUNT;
    mkdir(dirname);

    % save run parameters
    save([dirname,'/',imgFilename,'_1_runParameters.mat'],'start','dirname','CHANNELCOUNT','sigma','superVoxelOpts','maxIter','clusterCount','unitTest','graphData','numXpixels','numYpixels','numSlices','-v7.3')
end

%% denoise

if exist([dirname,'/',imgFilename,sprintf('_2_denoised_bm4d_colors%d_sigma%d.mat',CHANNELCOUNT,sigma)],'file')
    load([dirname,'/',imgFilename,sprintf('_2_denoised_bm4d_colors%d_sigma%d.mat',CHANNELCOUNT,sigma)])
else
    %% ingest img
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
    save([dirname,'/',imgFilename,sprintf('_2_denoised_bm4d_colors%d_sigma%d.mat',CHANNELCOUNT,sigma)], 'bbVol', '-v7.3')
end


%% normalize
if exist([dirname,'/',imgFilename,sprintf('_3_denoised_normalized_bm4d_colors%d_sigma%d.mat',CHANNELCOUNT,sigma)],'file')
    load([dirname,'/',imgFilename,sprintf('_3_denoised_normalized_bm4d_colors%d_sigma%d.mat',CHANNELCOUNT,sigma)])
else
    %% normalize each channel's intensity
    fprintf('\nNormalizing each channel''s intensity...');tic
    bbVol(bbVol<0)=0;
    parfor i = 1:CHANNELCOUNT
        rawStack = bbVol(:,:,:,i);
        rawStack = rawStack - min(rawStack(:)); 
        rawStack = rawStack / max(rawStack(:)); 
        bbVol(:,:,:,i) = rawStack;
    end
    save([dirname,'/',imgFilename,sprintf('_3_denoised_normalized_bm4d_colors%d_sigma%d.mat',CHANNELCOUNT,sigma)], 'bbVol', '-v7.3')
    fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))
end


%% watershed

%% watershed

if exist([dirname,'/',imgFilename,'_4_watershed.mat'],'file')
    load([dirname,'/',imgFilename,'_4_watershed.mat'])
else
    if exist([dirname,'/',imgFilename,'_3.5_watershed.mat'],'file')
        load([dirname,'/',imgFilename,'_3.5_watershed.mat'])
    else
        %% find the maximum intensity gradient of each point across all dimensions/colors
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


        %% 26-WATERSHED SEGMENTATION, 0 DENOTES WATERSHED BOUNDARIES
        % takes ~12min on 1 node
        fprintf('\nDetecting and removing the background...');tic
        L0 = double(watershed(imhmin(gradAmplitude, superVoxelOpts.HMINTH26), 26)); % L0: boundaries are 0, every voxel is labeled with the number of the segment it belongs to. NO BACKGROUND GIVEN???
        fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))
        fprintf('\nSaving L0...\n\n')
        save([dirname,'/',imgFilename,'_3.5_watershed.mat'],'L0','-v7.3')
    end
    
    %{
    * need some feature that returns a mask of L to label as "background"
    * for the moment using a dumb thresholding measure
        - threshold is chosen by identifying first peak in the distribution of intensities collapsed from normalized bbVol
    %}
    
    % choose threshold
    collapse  = sum(bbVol,4); %sum the normalized intensity across all channels
    h         = histogram(collapse(:)); % calculate the histogram of the distribution of these intensities
    [~,locs]  = findpeaks(h.Values); % find all the peaks in that frequency distribution
    threshold = h.Data(locs(1)); % set the threshold to be the intensity value in the very first (leftmost, closest to zero) peak 
    % actually, even this seems way too low in the real data

    
    % L1: 0 = boundary, 1 = background, 2...max(L1(:)) = watershed regions
    L1        = L0+1;
    L1(collapse < threshold) = 1; % set every voxel whose intensity is below the threshold to background (although this may disrupt some watershed regions; perhaps it should be before the watershed call?)
    L1(L0==0) = 0; % repaint the boundaries
    
    fprintf('\nSaving L1...\n\n')
    save([dirname,'/',imgFilename,'_4_watershed.mat'],'L1','L0','-v7.3')
    clear gradAmplitude;
end


%% filter on boundaries
if exist([dirname,'/',imgFilename,'_5_assign6.mat'],'file')
    load([dirname,'/',imgFilename,'_5_assign6.mat'])
else
    stackSize = size(L1);
    numVoxels = numel(L1);

    fprintf('\nAssigning watershed boundaries to objects...\n');tic % takes ~6000s = 1.66 hr on 1 node
%     exceeds intmax() when compiling on openmind ? not sure if there's a workaround
%     try
%         L2 = assign6BoundariesNB_mex(int16(L1), bbVol); % gets rid of boundaries; L2: 1 = background, 2...max(L2(:)) = watershed regions
%         disp('assign6BoundariesNB_mex requires casting to int16')
%     catch
%         try
%             L2 = assign6BoundariesNB_mex(int32(L1), bbVol); % gets rid of boundaries; L2: 1 = background, 2...max(L2(:)) = watershed regions
%             disp('assign6BoundariesNB_mex requires casting to int32')
%         catch
%             L2 = assign6BoundariesNB_mex(L1, bbVol); % gets rid of boundaries; L2: 1 = background, 2...max(L2(:)) = watershed regions
%             disp('assign6BoundariesNB_mex accepts L1 as a double')
%         end
%     end
    L2 = assign6BoundariesNB(L1, bbVol); % gets rid of boundaries; L2: 1 = background, 2...max(L2(:)) = watershed regions
    fprintf('\n                                               done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))

    % checkpoint
    fprintf('\nSaving L2...\n\n')
    save([dirname,'/',imgFilename,'_5_assign6.mat'], 'L2', 'stackSize','numVoxels','-v7.3')
end


%% filter out small supervoxels
if exist([dirname,'/',imgFilename,'_6_mask.mat'],'file')
    load([dirname,'/',imgFilename,'_6_mask.mat'])
else
    fprintf('\nRemoving small components...');tic % takes ~13860s = 3.8hrs on 1 node
    mask = removeSmallComponentsNB(L2~=1, superVoxelOpts.removeSmallComponents);
    fprintf(' done in %f seconds, total time: %s.\n',toc,char(datetime-start))
    fprintf('\nSaving mask...\n\n')
    save([dirname,'/',imgFilename,'_6_mask.mat'],'mask','-v7.3')
end


%% condense L
if exist([dirname,'/',imgFilename,'_7_condenseL.mat'],'file')
    load([dirname,'/',imgFilename,'_7_condenseL.mat'])    
else
    fprintf('\nCondensing...');tic
    
    % condense NB (test this in the full data set to make sure it works)
    % condense_begin=datetime;
    L3 = double(L2);
    L3(~mask) = 1;                                                          % 1 IS ASSIGNED TO BACKGROUND IN THIS DATASET - SHOULD REVISE FOR GENERAL CASE?
    fprintf('\nRemoved %d small components, %d components remain.\n',max(L0(:))-numel(unique(L3)),numel(unique(L3)));
    L3 = condense_mex(L3);
    %L3 = condense_spmd(L3); % SLOW WHEN SMALL BUT MAYBE FASTER AT SCALE?
    
    fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))

    % checkpoint 
    fprintf('\nSaving L3...\n\n')
    save([dirname,'/',imgFilename,'_7_condenseL.mat'], 'L3', '-v7.3')
end


%% store supervoxels 
if exist([dirname,'/',imgFilename,'_8_superVoxelCells.mat'],'file')
    load([dirname,'/',imgFilename,'_8_superVoxelCells.mat'])
else
    % takes ~30min
    superVoxelCells = cell(1,max(L3(:))-1);                                      % 1 IS ASSIGNED TO BACKGROUND IN THIS DATASET - SHOULD REVISE FOR GENERAL CASE
    fprintf('\nForming supervoxels...');tic
    parfor i = 1:max(L3(:))-1
        superVoxelCells{i} = find(L3==i+1);                                      % (superVoxelCells is a cell array where each cell is a list of the linear indices of L where that cell's supervoxel has pixels)
    end
    fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))

    % checkpoint
    fprintf('\nSaving superVoxelCells...\n\n')
    save([dirname,'/',imgFilename,'_8_superVoxelCells.mat'],'superVoxelCells','-v7.3')
end


%% split heterogeneous supervoxels
if exist([dirname,'/',imgFilename,'_9_LsuperVoxelCells.mat'],'file')
    load([dirname,'/',imgFilename,'_9_LsuperVoxelCells.mat'])
else
    % takes about 14785s = 4.1hrs
    fprintf('\nSplitting heterogeneous supervoxels...');tic
    [L4, superVoxelCells] = splitHardSuperVoxelsUS(superVoxelOpts.splitHardSVopts, superVoxelCells, bbVol); 
    fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))

    % checkpoint
    fprintf('\nSaving L4, superVoxelCells...\n\n')
    save([dirname,'/',imgFilename,'_9_LsuperVoxelCells.mat'],'superVoxelCells','L4','-v7.3')
end

%% get supervoxel means, boundaries
if exist([dirname,'/',imgFilename,'_10_superVoxelBoundaries.mat'],'file')
    load([dirname,'/',imgFilename,'_10_superVoxelBoundaries.mat'])
else
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
    fprintf('\nSaving supervoxel boundaries...\n\n')
    save([dirname,'/',imgFilename,'_10_superVoxelBoundaries.mat'], 'cc', 'superVoxelCells', 'superVoxelMeans', 'boundaryVoxelsSub', '-v7.3')
end

%% calculate supervoxel affinities
if exist([dirname,'/',imgFilename,'_11_superVoxelAffinities.mat'],'file')
    load([dirname,'/',imgFilename,'_11_superVoxelAffinities.mat'])
else
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
    fprintf('\nSaving supervoxel affinities...\n\n')
    save([dirname,'/',imgFilename,'_11_superVoxelAffinities.mat'], 'sAff','cc', 'boundaryVoxelsSub', 'superVoxelOpts','square_sAff', '-v7.3');
end


%% initial clustering
if exist([dirname,'/',imgFilename,'_12_clustering.mat'],'file')
    load([dirname,'/',imgFilename,'_12_clustering.mat'])
else
    fprintf('\nClustering...');tic
    voxelCounts                     = cellfun(@numel,superVoxelCells)';

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
    save([dirname,'/',imgFilename,'_12_clustering.mat'],'superVoxelMeansLUV','index','opts_fkmeans','-v7.3');
    save([dirname,'/',imgFilename,'_ForStefanie.mat'],'superVoxelMeansLUV','superVoxelMeans','square_sAff');
end



%% human interaction

segProjectionWrite
save([dirname,'/',imgFilename,'_13_forManipulation.mat'],'index','graphData','opts_fkmeans','superVoxelMeansLUV','square_sAff','voxelCounts','stackSize','superVoxelCells','numXpixels','numYpixels','-V7.3');

fprintf('superVoxelize1 done in %s.\n\n',char(datetime-start))

cd(dirname)
profsave
cd ..
delete(pool)
exit

%{
human chooses which superVoxels to manipulatethrough manipulateClusters which spits back out the
index (which may have entries <1 in it)
which is then fed into calculateNormalizedCuts_mem through the following
code:

(if you like segprojection enough after snrKmeans, you can stop there.
essentially, calculateNormalizedCuts_mem is a way of refining the color
segmentation and takes as input human decisions that reduce the Nk landscape
it has to search through)

human looks at collage of 2D supervoxel projections in the image generated 
in segProjectionWrite and specifies which to split/merge/delete/etc via
manipulationSets
%}

%% superVoxelize2.m (replace old file contents)
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


%% superVoxelize3.m
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

% fprintf('\nVisualizing supervoxels...');tic
% segProjectionWrite
% fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))

%% finish up
%save([dirname 'varsForRunUygar2.mat'],'index','stackSize','superVoxelCells','numXpixels','numYpixels','dirname','imgFilename','superVoxelMeansLUV', 'opts_fkmeans','graphData','square_sAff','voxelCounts')
