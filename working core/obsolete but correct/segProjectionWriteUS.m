clusterCount                                 = max(index);
segmentation                                 = zeros(stackSize);

for kka = 1:clusterCount
    thisCluster = find(index==kka);
    for kkb = 1:numel(thisCluster)
        segmentation(superVoxelCells{thisCluster(kkb)}) = kka;              % (assign kka to all of the voxels in segmentation which have been labeled with this cluster)
    end
end

numVoxels                                    = numel(segmentation);

xTileCount                                   = ceil(sqrt(clusterCount/40) * 5);
yTileCount                                   = ceil(clusterCount/xTileCount);

if ~exist('bbVol','var');fn = dir([dirname,'/',imgFileName,'_denoised_normalized*.mat']);load(fn.name);end;
bigIm                                        = ones((numYpixels+1)*yTileCount-1, (numXpixels+1)*xTileCount-1, 3);
for i=1:clusterCount
	[xTile, yTile]                           = ind2sub([xTileCount yTileCount], i);
	tmp2                                     = find(segmentation==i);
    for mm = 1:3
        tmp1                                 = zeros(stackSize);
        tmp1(tmp2)                           = bbVol(tmp2+(mm-1)*numVoxels);
        bigIm(((yTile-1)*(numYpixels+1)+1):(yTile*(numYpixels+1)-1), ((xTile-1)*(numXpixels+1)+1):(xTile*(numXpixels+1)-1), mm) = max(tmp1, [], 3);
    end
end

jpgFilepath = sprintf('%s/%s_%d.jpg',dirname,imgFilename,length(dir('%s/%s*.jpg')));
imwrite(bigIm, jpgFilepath);                                                % each tile of this jpg is a different supervoxel
