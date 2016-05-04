segmentation                                                                                             = zeros(stackSize);
for kka = 1:clusterCount
    thisCluster                                                                                          = find(index==kka);
    for kkb = 1:numel(thisCluster)
        segmentation(superVoxelCells{thisCluster(kkb)})                                                  = kka;
    end
end
[xx, yy, zz]                                                                                             = size(segmentation);
xTileCount                                                                                               = ceil(sqrt(clusterCount/40) * 5);
yTileCount                                                                                               = ceil(clusterCount/xTileCount);
compx                                                                                                    = xx + zz;
compy                                                                                                    = yy + zz;
bigIm                                                                                                    = ones((xx+1)   *xTileCount-1, (yy+1)   *yTileCount-1, 3);
bigImxyz                                                                                                 = ones((compx+1)*xTileCount-1, (compy+1)*yTileCount-1, 3);
for kk=1:clusterCount
    [xTile, yTile]                                                                                           = ind2sub([xTileCount yTileCount], kk);
    tmp2                                                                                                     = find(segmentation==kk);
    for mm = 1:3
        tmp1                                                                                                 = zeros(xx, yy, zz);
        tmp1(tmp2)                                                                                           = bbVol(tmp2+(mm-1)*numVoxels);
        xyImage                                                                                              = max(tmp1, [], 3);
        zyImage                                                                                              = permute(max(tmp1, [], 1), [3 2 1]);
        xzImage                                                                                              = max(tmp1, [], 2);
        bigIm((xTile-1)*(xx+1)+1:xTile*(xx+1)-1, (yTile-1)*(yy+1)+1:yTile*(yy+1)-1, mm)                      = xyImage;
        bigImxyz((xTile-1)*(compx+1)+1:xTile*(compx+1)-zz-1, (yTile-1)*(compy+1)+1:yTile*(compy+1)-zz-1, mm) = xyImage;
        bigImxyz((xTile-1)*(compx+1)+1:xTile*(compx+1)-zz-1, (yTile-1)*(compy+1)+yy+1:yTile*(compy+1)-1, mm) = xzImage;
        bigImxyz((xTile-1)*(compx+1)+xx+1:xTile*(compx+1)-1, (yTile-1)*(compy+1)+1:yTile*(compy+1)-zz-1, mm) = zyImage;
    end
end

jpgFilepath = sprintf('%s/%s_XYZ_%d.jpg',dirname,imgFilename,length(dir('%s/%s*.jpg')));
imwrite(bigImxyz, jpgFilepath);                                                % each tile of this jpg is a different supervoxel
