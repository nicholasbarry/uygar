function [superVoxelCells] = splitHardSuperVoxels_kmeansNB3(splitHardSVopts, superVoxelCells, bbVol)

stackSize        = size(bbVol);
stackSize        = stackSize(1:3);
voxelCount       = prod(stackSize);
detcov           = zeros(1, numel(superVoxelCells));
counts           = cellfun(@numel,superVoxelCells);
%%%% for fun %%%%
%idxs             = sortrows([counts; 1:numel(counts)]');
%superVoxelCells  = superVoxelCells(idxs(:,2));
%%%%%%%%%%%%%%%%%
shift_by_channel = voxelCount*(0:size(bbVol, 4)-1);

for kk=1:numel(superVoxelCells)
    [foo, bar] = meshgrid(shift_by_channel,superVoxelCells{kk});
    tmp        = bbVol(foo+bar);
    tmp        = tmp ./ repmat(sqrt(sum(tmp.^2,2)),1,size(tmp,2));
    detcov(kk) = det(cov(tmp));
end
detcov(counts<2)=0;

hardSVidxs = find((detcov>splitHardSVopts.detThreshold) & (counts > splitHardSVopts.subdivisionSizeThreshold)); % list of indices of superVoxelCells that are variable in colorspace and not too small
iterCount       = 0;
fprintf(' %d supervoxels to go.\n', numel(hardSVidxs));


while ~isempty(hardSVidxs)
  
    prevSVcount = numel(superVoxelCells);
    newCells    = cell(1, numel(hardSVidxs));

    fprintf('\nSubdividing... ');tic
    parfor kk = 1:numel(hardSVidxs)
        
        allVox = superVoxelCells{hardSVidxs(kk)};
        
        % SUBDIVIDE BASED ON COLOR
        [foo,bar]           = meshgrid(shift_by_channel, allVox);
        normalizedColorData = bbVol(foo+bar);
        
        % for every voxel, divide the intensity in every color channel but the square root of the sum of the squares of the individual color channel values
        normalizedColorData = normalizedColorData ./ repmat(sqrt(sum(normalizedColorData.^2,2)),[1 numel(shift_by_channel)]); 
        T                   = snrAwareKmeans(normalizedColorData, 2, splitHardSVopts.opts_fkmeans);
        
        % SUBDIVIDE EACH PIECE AGAIN BASED ON CONNECTIVITY
        CC1 = connectedcomponentsInLocalCoordinates(stackSize, allVox(T==1), splitHardSVopts.connectivity);
        CC2 = connectedcomponentsInLocalCoordinates(stackSize, allVox(T==2), splitHardSVopts.connectivity);
        newCells{kk} = [CC1.PixelIdxList CC2.PixelIdxList];
        
    end
    newCells                         = cat(2,newCells{:});
    fprintf('complete in %f seconds.\n',toc)
    
    % identify which of newCells need splitting
    detcov1 = size(newCells);
    counts1 = cellfun(@numel,newCells);
    
    parfor kk=1:numel(newCells)
        if numel(newCells{kk})>1
            [foo, bar] = meshgrid(shift_by_channel,newCells{kk});
            tmp        = bbVol(foo+bar);
            tmp        = tmp ./ repmat(sqrt(sum(tmp.^2,2)),1,size(tmp,2));
            detcov1(kk) = det(cov(tmp));
            counts1(kk) = numel(newCells{kk});
        else
            detcov1(kk) = 0;
            counts1(kk) = 1;
        end
    end
    

    %{
    newSVcount                       = numel(newCells);
    superVoxelCells(hardSVidxs) = [];
    detcov(hardSVidxs)          = [];
    counts(hardSVidxs)          = [];
    detcov                           = [detcov, zeros(1, newSVcount)];
    counts                           = [counts, zeros(1, newSVcount)];
    svCountBeforeAddition            = numel(detcov) - newSVcount;
    superVoxelCells                  = cat(2,superVoxelCells, newCells);
    
    parfor kk = svCountBeforeAddition+1:svCountBeforeAddition+newSVcount
        
        if numel(superVoxelCells{kk})>1
            
            [foo, bar] = meshgrid(shift_by_channel,superVoxelCells{kk});
            tmp        = bbVol(foo+bar);
            tmp        = tmp ./ repmat(sqrt(sum(tmp.^2,2)),1,size(tmp,2));
            detcov(kk) = det(cov(tmp));
            counts(kk) = numel(superVoxelCells{kk});
        else
            detcov(kk) = 0;
            counts(kk) = 1;
        end
        
    end
    %}
    hardSVidxs = find((detcov1>splitHardSVopts.detThreshold) & (counts1 > splitHardSVopts.subdivisionSizeThreshold)); % list of indices of superVoxelCells that are variable in colorspace and not too small
    hardSVbool = (detcov1>splitHardSVopts.detThreshold) & (counts1 > splitHardSVopts.subdivisionSizeThreshold);
    superVoxelCells = cat(2,superVoxelCells, newCells(~hardSVbool));
    hardsuperVoxels = newCells(hardSVidxs);
    
    if prevSVcount==numel(superVoxelCells);break;end
    iterCount       = iterCount + 1;
    fprintf('\nIteration %d complete. hardsuperVoxels: %d. superVoxels: .\n',iterCount,newSVcount,numel(superVoxelCells));
    
end

fprintf('splitHardSuperVoxels iterated %d times before converging.',iterCount);

end

function [myCC] = connectedcomponentsInLocalCoordinates(stackSize, theseVoxels, connectivity)
[xx,yy,zz]              = ind2sub(stackSize, theseVoxels);
xSub                    = min(xx)-1;
ySub                    = min(yy)-1;
zSub                    = min(zz)-1;
xx                      = xx-xSub;
yy                      = yy-ySub;
zz                      = zz-zSub;
maxxx                   = max(xx);
maxyy                   = max(yy);
maxzz                   = max(zz);
tmp                     = false(maxxx, maxyy, maxzz);
reducedIndices          = sub2ind([maxxx, maxyy, maxzz], xx, yy, zz);
tmp(reducedIndices)     = true;
myCC                    = bwconncomp(tmp, connectivity);
for nn = 1:numel(myCC.PixelIdxList)
    [xx,yy,zz]            = ind2sub(size(tmp), myCC.PixelIdxList{nn});
    xx                    = xx+xSub;
    yy                    = yy+ySub;
    zz                    = zz+zSub;
    myCC.PixelIdxList{nn} = sub2ind(stackSize, xx, yy, zz);
end
end