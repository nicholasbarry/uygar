function [sAff, sAffPos, sAffVal] = calculate_sAffNB(cc, boundaryVoxelsSub, spatialDistanceUpperBound)

potentialNeighbors       = cell(cc, 1);
neighbors                = cell(cc, 1);
sAffVals                 = cell(cc, 1);
squaredThreshold         = spatialDistanceUpperBound^2;
numVox                   = cellfun(@(x) size(x,1),boundaryVoxelsSub);
minXYZ                   = cellfun(@(x) min(x,[],1),boundaryVoxelsSub,'UniformOutput',false);
maxXYZ                   = cellfun(@(x) max(x,[],1),boundaryVoxelsSub,'UniformOutput',false);
minXYZ                   = cat(1,minXYZ{:});
maxXYZ                   = cat(1,maxXYZ{:});
% minXYZ/maxXYZ are numel(superVoxels)x3 arrays with one row per supervoxel. 
% each row contains the min/max X,Y,Z indices of that row's corresponding supervoxel

%% SORT THE MIN AND MAX VOXEL POSITIONS OF SUPERVOXELS IN EACH DIMENSION, NOTE THE SORTED ORDER OF EACH SUPERVOXEL IN EACH SORTED LIST

[~, minIdxX]             = sort(minXYZ(:,1)); posMinX(minIdxX) = 1:cc;
[~, maxIdxX]             = sort(maxXYZ(:,1)); posMaxX(maxIdxX) = 1:cc;
[~, minIdxY]             = sort(minXYZ(:,2)); posMinY(minIdxY) = 1:cc;
[~, maxIdxY]             = sort(maxXYZ(:,2)); posMaxY(maxIdxY) = 1:cc;
[~, minIdxZ]             = sort(minXYZ(:,3)); posMinZ(minIdxZ) = 1:cc;
[~, maxIdxZ]             = sort(maxXYZ(:,3)); posMaxZ(maxIdxZ) = 1:cc;

%% GENERATE KD TREES FOR MIN AND MAX VOXEL POSITIONS IN EACH DIMENSION

MdlMinX                  = KDTreeSearcher(minXYZ(:, 1));
MdlMinY                  = KDTreeSearcher(minXYZ(:, 2));
MdlMinZ                  = KDTreeSearcher(minXYZ(:, 3));
MdlMaxX                  = KDTreeSearcher(maxXYZ(:, 1));
MdlMaxY                  = KDTreeSearcher(maxXYZ(:, 2));
MdlMaxZ                  = KDTreeSearcher(maxXYZ(:, 3));

%% 1. FIND SUPERVOXELS WHOSE MIN OR MAX VALUES ARE NOT MORE THAN thisBound APART FROM THE MIN VALUE OF THE SUPERVOXEL IN QUESTION
%% 2. ADD THE SUPERVOXELS WHOSE MIN VALUES ARE SMALLER THAN THE MIN OF THE SUPERVOXEL IN QUESTION AND MAX VALUES ARE LARGER THAN THE MAX OF THE SUPERVOXEL IN QUESTION
%% 3. RETAIN ONLY THE POTENTIAL NEIGHBORS THAT ARE PROXIMAL IN ALL DIMENSIONS
%% 4. CONSIDER ONLY THE LOWER TRIANGULAR PART TO SAVE SPACE AND COMPUTATIONS
sectionTime = datetime;
parfor kk = 2:cc
    thisBound              = (maxXYZ(kk,1) - minXYZ(kk,1)) + spatialDistanceUpperBound;
    tt                     = rangesearch(MdlMinX, minXYZ(kk,1), thisBound);
    potentialNeighbors{kk} = tt{1};
    tt                     = rangesearch(MdlMaxX, minXYZ(kk,1), thisBound);
    potentialNeighbors{kk} = union(potentialNeighbors{kk}, tt{1}, 'stable');
    potentialNeighbors{kk} = union(potentialNeighbors{kk}, intersect(minIdxX(1:posMinX(kk)-1), maxIdxX(posMaxX(kk)+1:end), 'stable'), 'stable');
    
    thisBound              = (maxXYZ(kk,2) - minXYZ(kk,2)) + spatialDistanceUpperBound;
    tt                     = rangesearch(MdlMinY, minXYZ(kk,2), thisBound);
    potentialNeighborsY    = tt{1};
    tt                     = rangesearch(MdlMaxY, minXYZ(kk,2), thisBound);
    potentialNeighborsY    = union(potentialNeighborsY, tt{1}, 'stable');
    potentialNeighborsY    = union(potentialNeighborsY, intersect(minIdxY(1:posMinY(kk)-1), maxIdxY(posMaxY(kk)+1:end), 'stable'), 'stable');
    potentialNeighbors{kk} = intersect(potentialNeighbors{kk}, potentialNeighborsY, 'stable');
    
    thisBound              = (maxXYZ(kk,3) - minXYZ(kk,3)) + spatialDistanceUpperBound;
    tt                     = rangesearch(MdlMinZ, minXYZ(kk,3), thisBound);
    potentialNeighborsZ    = tt{1};
    tt                     = rangesearch(MdlMaxZ, minXYZ(kk,3), thisBound);
    potentialNeighborsZ    = union(potentialNeighborsZ, tt{1}, 'stable');
    potentialNeighborsZ    = union(potentialNeighborsZ, intersect(minIdxZ(1:posMinZ(kk)-1), maxIdxZ(posMaxZ(kk)+1:end), 'stable'), 'stable');
    potentialNeighbors{kk} = intersect(potentialNeighbors{kk}, potentialNeighborsZ, 'stable');
    
    potentialNeighbors{kk} = potentialNeighbors{kk}(potentialNeighbors{kk}<kk);
    
    if mod(kk,1000) == 0;fprintf('%d/%d done in %s.\n',kk,cc,char(datetime-sectionTime));end
end

%{
theseBounds                = (maxXYZ-minXYZ) + spatialDistanceUpperBound;

parfor kk = 2:cc
    thisBound              = theseBounds(kk,:);
    
    xMin                   = rangesearch(MdlMinX, minXYZ(kk,1), thisBound(1));
    xMax                   = rangesearch(MdlMaxX, minXYZ(kk,1), thisBound(1));
    potentialNeighborsX    = union([xMin{1}; xMax{1}], intersect(minIdxX(1:posMinX(kk)-1), maxIdxX(posMaxX(kk)+1:end), 'stable'), 'stable');
    
    yMin                   = rangesearch(MdlMinY, minXYZ(kk,2), thisBound(2));
    yMax                   = rangesearch(MdlMaxY, minXYZ(kk,2), thisBound(2));
    potentialNeighborsY    = union([yMin{1}; yMax{1}], intersect(minIdxY(1:posMinY(kk)-1), maxIdxY(posMaxY(kk)+1:end), 'stable'), 'stable');
    
    zMin                   = rangesearch(MdlMinZ, minXYZ(kk,3), thisBound(3));
    zMax                   = rangesearch(MdlMaxZ, minXYZ(kk,3), thisBound(3));
    potentialNeighborsZ    = union([zMin{1}; zMax{1}], intersect(minIdxZ(1:posMinZ(kk)-1), maxIdxZ(posMaxZ(kk)+1:end), 'stable'), 'stable');
    
    potentialNeighborsXYZ  = intersect([potentialNeighborsX; potentialNeighborsY], potentialNeighborsZ, 'stable');
    potentialNeighbors{kk} = potentialNeighborsXYZ(potentialNeighborsXYZ < kk);
    
end
%}
%% CALCULATE THE DISTANCE BETWEEN THE BOUNDARY VOXELS FOR EACH SUPERVOXEL AND ITS POTENTIAL NEIGHBORS
%% DISTANCES LESS THAN THE THRESHOLD VALUE ARE GUARANTEED TO BE CALCULATED CORRECTLY
%% DISTANCES LARGER THAN THE THRESHOLD VALUE MAY BE ASSIGNED INFINITY OR CALCULATED CORRECTLY
sectionTime = datetime;
parfor kk1 = 1:cc
    kk1Time = datetime;
    minkk1 = minXYZ(kk1,:);
    maxkk1 = maxXYZ(kk1,:);
    
    these_neighbors = zeros(1,numel(potentialNeighbors{kk1}));
    these_sAffVals  = zeros(1,numel(potentialNeighbors{kk1})) - 1;
    
    for mm = 1:numel(potentialNeighbors{kk1})
        
        kk2 = potentialNeighbors{kk1}(mm);
        
        minkk2 = minXYZ(kk2,:);
        maxkk2 = maxXYZ(kk2,:);
        
        if sum( ( (minkk1 - maxkk2).*(maxkk2 < minkk1) + (minkk2 - maxkk1).*(maxkk1 < minkk2) ) .^2 ) < squaredThreshold % this logic is correct
            
            if numVox(kk1)*numVox(kk2) < 1e3
                
                sVal = 1/min(min(pdist2(boundaryVoxelsSub{kk1}, boundaryVoxelsSub{kk2})));
                
            else

                sVal = spatialAffinityBetweenObjectPairForLargeObjects(boundaryVoxelsSub{kk1}, boundaryVoxelsSub{kk2}, minkk1, maxkk1, minkk2, maxkk2, spatialDistanceUpperBound);

            end
            these_neighbors(mm) = kk2;
            these_sAffVals(mm)  = sVal;
        end
    end
    
    neighbors{kk1} = these_neighbors(these_neighbors~=0);
    sAffVals{kk1}  = these_sAffVals(these_sAffVals~=-1);
    
    fprintf('SV %d (%d neighbors) done in %s, total time %s.\n',kk1,numVox(kk1),char(datetime-kk1Time),char(datetime-sectionTime));
end

%% GENERATE A SPARSE REPRESENTATION OF THE VECTORIZED SPATIAL AFFINITIES
sAffPos                                = cellfun(@(x,y) cc*x - cc - x.*(x+1)/2 + y, neighbors, num2cell(1:cc)','UniformOutput',false);
sAffPos                                = cat(2,sAffPos{:}); % or sAffPos                                = cat(1,sAffPos{:})';
sAffVal                                = cat(2,sAffVals{:});
sAff                                   = sparse(sAffPos, 1, sAffVal, cc*(cc-1)/2, 1);