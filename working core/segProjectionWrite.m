function [jpgFilepath] = segProjectionWrite(stackSize,clusterCount,index,superVoxelCells,dirname,imgFilename,bbVol,numXpixels,numYpixels,superVoxelOpts)

segmentation                                 = zeros(stackSize);

for kka = 1:clusterCount
    thisCluster = find(index==kka); % find the indices of all the superVoxels in this cluster
    for kkb = 1:numel(thisCluster) % for every superVoxel in this cluster
        segmentation(superVoxelCells{thisCluster(kkb)}) = kka;              % (assign kka to all of the voxels in segmentation which have been labeled with this cluster)
    end
end

xTileCount                                   = ceil(sqrt(clusterCount/40) * 5);
yTileCount                                   = ceil(clusterCount/xTileCount);

%if ~exist('bbVol','var');fn = dir([dirname,'/',imgFileName,'_denoised_normalized*.mat']);load(fn.name);end;
bigIm                                        = ones((numYpixels+1)*yTileCount-1, (numXpixels+1)*xTileCount-1, 3);
[xTile, yTile]                               = ind2sub([xTileCount yTileCount], 1:clusterCount);
yStart = (yTile-1) * (numYpixels+1) + 1;
xStart = (xTile-1) * (numXpixels+1) + 1;
yStop  = yTile * (numYpixels+1) - 1;
xStop  = xTile * (numXpixels+1) - 1;
for i=1:clusterCount
    bigIm(yStart(i):yStop(i), xStart(i):xStop(i), :) = squeeze((max(bbVol.*(repmat(segmentation==i,[1 1 1 3])),[],3)));
end

%jpgFilepath = sprintf('%s/%s_%d.jpg',dirname,imgFilename,length(dir(sprintf('%s/%s*.jpg',dirname,imgFilename))));
jpgFilepath = sprintf('%s/%s_HMINTH%g_spatialUB%d_colorUB%g_detTh%g_subdivTh%d_minVox%d_cc%d_%d.jpg',dirname,imgFilename,superVoxelOpts.HMINTH26,superVoxelOpts.spatialDistanceUpperBound,superVoxelOpts.colorDistanceUpperBound,superVoxelOpts.splitHardSVopts.detThreshold,superVoxelOpts.splitHardSVopts.subdivisionSizeThreshold,superVoxelOpts.removeSmallComponents.minVoxelCount,clusterCount,length(dir(sprintf('%s/%s*.jpg',dirname,imgFilename))));
imwrite(bigIm, jpgFilepath);                                               % each tile of this jpg is a different supervoxel
end