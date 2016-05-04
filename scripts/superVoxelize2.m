% % supervision correction
% 
% % from save('varsForRunUygar2.mat','index','stackSize','superVoxelCells','numXpixels','numYpixels','dirname','imgFilename','superVoxelMeansLUV','opts_fkmeans','graphData','square_sAff','voxelCounts') in superVoxelize1
% load('varsForRunUygar2.mat')
% load(sprintf('%s/%s_denoisedbm4d_colors%d_sigma%d.mat',dirname,imgFilename,CHANNELCOUNT,sigma));
% 
% %% manipulateClusters
% 
% fprintf('\nManipulating supervoxels...');tic
% [index] = manipulateClusters(index, manipulationSets, superVoxelMeansLUV, opts_fkmeans);
% fprintf(' done in %f seconds.\n\n',toc)
% 
% segProjectionWrite
% 
% if ~strcmp(java.lang.System.getProperty('java.awt.headless'),'true')
%     imshow(jpgFilepath);
% end
% 
% %% prep for next round
% save([dirname '/varsForRunUygar2.mat'],'index','stackSize','superVoxelCells','numXpixels','numYpixels','dirname','imgFilename','superVoxelMeansLUV', 'opts_fkmeans','graphData','square_sAff','voxelCounts')

%% superVoxelize2.m

% pass it imgFilePath to set up / save out properly
% pass it manipulationSets to manipulateClusters
% repeat this script until satisfied

[~,imgFilename,~]                                        = fileparts(imgFilePath);
dirname                                                  = [imgFilename,'_','Segmentation'];
load([dirname,'/',imgFilename,'_forManipulation.mat']);

fprintf('\nManipulating supervoxels...');tic
indexUI = manipulateClusters(index, manipulationSets, superVoxelMeansLUV, opts_fkmeans);
fprintf(' done in %f seconds.\n\n',toc)

segprojectionWrite

if ~strcmp(java.lang.System.getProperty('java.awt.headless'),'true')
    imshow(jpgFilepath);
end

save([dirname,'/',imgFilename,'_forGraphCuts.mat'],'-V7.3');