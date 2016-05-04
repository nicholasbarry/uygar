%% superVoxelize3.m
%{
% pass it imgFilePath to set up / save out properly

%}
[~,imgFilename,~]                                        = fileparts(imgFilePath);
dirname                                                  = [imgFilename,'_','Segmentation'];
load([dirname,'/',imgFilename,'_forGraphCuts.mat']);
start = datetime;

fprintf('\nFinding seed sets...');tic
seedSets = cell(max(indexUI),1);
for kk = 1:max(indexUI)
  seedSets{kk} = find(indexUI==kk);
end
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))

% calculateNormalizedCuts_mem
graphData.seedSets           = seedSets;
graphData.ccIDsOfSVs         = indexUI;
graphData.colorData          = superVoxelMeansLUV;
graphData.square_sAff        = square_sAff;
graphData.svSizes            = voxelCounts;
graphData.stackSize          = stackSize;
graphData.minClumpCount      = 0.005 * numel(superVoxelCells) / graphData.opts_irbleigs.K;
graphData.minSVcountFraction = 0.1 / graphData.opts_irbleigs.K;

fprintf('\nCalculating normalized cuts...');tic
[index, scoreInf, score1]    = calculateNormalizedCuts_mem(graphData);
fprintf(' done in %f seconds, total time: %s.\n\n',toc,char(datetime-start))

% inspect
segProjectionWrite

% checkpoint
save([dirname,'/',imgFilename,'_forManipulation.mat'],'-v7.3');