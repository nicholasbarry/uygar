function [sAff, sAffPos, sAffVal] = calculate_sAff(cc, boundaryVoxelsSub, spatialDistanceUpperBound)
sectionTime = datetime;
potentialNeighbors       = cell(cc, 1);
neighbors                = cell(cc, 1);
sAffVals                 = cell(cc, 1);
squaredThreshold         = spatialDistanceUpperBound^2;
numVox                   = cellfun(@(x) size(x,1),boundaryVoxelsSub);
minXYZ                   = cellfun(@(x) min(x,[],1),boundaryVoxelsSub,'UniformOutput',false);
maxXYZ                   = cellfun(@(x) max(x,[],1),boundaryVoxelsSub,'UniformOutput',false);
minXYZ                   = cat(1,minXYZ{:});
maxXYZ                   = cat(1,maxXYZ{:});
fprintf('Startup section done in %s\n',char(datetime-sectionTime));
%% SORT THE MIN AND MAX VOXEL POSITIONS OF SUPERVOXELS IN EACH DIMENSION, NOTE THE SORTED ORDER OF EACH SUPERVOXEL IN EACH SORTED LIST
sectionTime = datetime;
[~, minIdxX]             = sort(minXYZ(:,1)); posMinX(minIdxX) = 1:cc;
[~, maxIdxX]             = sort(maxXYZ(:,1)); posMaxX(maxIdxX) = 1:cc;
[~, minIdxY]             = sort(minXYZ(:,2)); posMinY(minIdxY) = 1:cc;
[~, maxIdxY]             = sort(maxXYZ(:,2)); posMaxY(maxIdxY) = 1:cc;
[~, minIdxZ]             = sort(minXYZ(:,3)); posMinZ(minIdxZ) = 1:cc;
[~, maxIdxZ]             = sort(maxXYZ(:,3)); posMaxZ(maxIdxZ) = 1:cc;
fprintf('SORT THE MIN AND MAX VOXEL POSITIONS OF SUPERVOXELS IN EACH DIMENSION, NOTE THE SORTED ORDER OF EACH SUPERVOXEL IN EACH SORTED LIST, done in %s\n',char(datetime-sectionTime))
%% GENERATE KD TREES FOR MIN AND MAX VOXEL POSITIONS IN EACH DIMENSION
sectionTime = datetime;
MdlMinX                  = KDTreeSearcher(minXYZ(:, 1));
MdlMinY                  = KDTreeSearcher(minXYZ(:, 2));
MdlMinZ                  = KDTreeSearcher(minXYZ(:, 3));
MdlMaxX                  = KDTreeSearcher(maxXYZ(:, 1));
MdlMaxY                  = KDTreeSearcher(maxXYZ(:, 2));
MdlMaxZ                  = KDTreeSearcher(maxXYZ(:, 3));
fprintf('GENERATE KD TREES FOR MIN AND MAX VOXEL POSITIONS IN EACH DIMENSION, done in %s. \n',char(datetime-sectionTime));
%% 1. FIND SUPERVOXELS WHOSE MIN OR MAX VALUES ARE NOT MORE THAN thissBound APART FROM THE MIN VALUE OF THE SUPERVOXEL IN QUESTION
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
fprintf('FIND SUPERVOXELS WHOSE MIN OR MAX VALUES ARE NOT MORE THAN thissBound APART FROM THE MIN VALUE OF THE SUPERVOXEL IN QUESTION, done in %s. \n',char(datetime-sectionTime));
%% CALCULATE THE DISTANCE BETWEEN THE BOUNDARY VOXELS FOR EACH SUPERVOXEL AND ITS POTENTIAL NEIGHBORS
%% DISTANCES LESS THAN THE THRESHOLD VALUE ARE GUARANTEED TO BE CALCULATED CORRECTLY
%% DISTANCES LARGER THAN THE THRESHOLD VALUE MAY BE ASSIGNED INFINITY OR CALCULATED CORRECTLY
sectionTime = datetime;
parfor kk1 = 1:cc
    kk1Time = datetime;
    for mm = 1:numel(potentialNeighbors{kk1})
        kk2 = potentialNeighbors{kk1}(mm);
        if sum( ( (minXYZ(kk1,:)-maxXYZ(kk2,:)).*(maxXYZ(kk2,:)<minXYZ(kk1,:)) + (minXYZ(kk2,:)-maxXYZ(kk1,:)).*(maxXYZ(kk1,:)<minXYZ(kk2,:)) ).^2 ) < squaredThreshold
            if size(boundaryVoxelsSub{kk1},1)*size(boundaryVoxelsSub{kk2},1)<1e3
                sVal = 1/min(min(pdist2(boundaryVoxelsSub{kk1}, boundaryVoxelsSub{kk2})));
            else
                sVal = spatialAffinityBetweenObjectPairForLargeObjects(boundaryVoxelsSub{kk1}, boundaryVoxelsSub{kk2}, minXYZ(kk1,:), maxXYZ(kk1,:), minXYZ(kk2,:), maxXYZ(kk2,:), spatialDistanceUpperBound);
            end
            neighbors{kk1}(end+1) = kk2;
            sAffVals{kk1}(end+1)  = sVal;
        end
    end
    %fprintf('SV %d (%d voxels) done in %s, total time %s.\n',kk1,numel(superVoxelCells{kk1}),char(datetime-kk1Time),char(datetime-sectionTime));
    %if mod(kk1,1000) == 0;fprintf('SV %d (%d voxels) done in %s, total time %s.\n',kk1,numel(superVoxelCells{kk1}),char(datetime-kk1Time),char(datetime-sectionTime));end;
    %if mod(kk1,1000) == 0;fprintf('%d/%d done in %s.\n',kk1,cc,char(datetime-sectionTime));end
end
sAffPos = [];
sAffVal = [];
fprintf('CALCULATE THE DISTANCE BETWEEN THE BOUNDARY VOXELS FOR EACH SUPERVOXEL AND ITS POTENTIAL NEIGHBORS, done in %s.\n',char(datetime-sectionTime));
%% GENERATE A SPARSE REPRESENTATION OF THE VECTORIZED SPATIAL AFFINITIES
sectionTime = datetime;
for kk = 2:cc
    if ~isempty(neighbors{kk})
        sAffPos = [sAffPos cc*neighbors{kk} - cc - neighbors{kk}.*(neighbors{kk}+1)/2 + kk];
        sAffVal = [sAffVal sAffVals{kk}];
    end
end
fprintf('GENERATE A SPARSE REPRESENTATION OF THE VECTORIZED SPATIAL AFFINITIES, done in %s.\n',char(datetime-sectionTime));
sAff = sparse(sAffPos, 1, sAffVal, cc*(cc-1)/2, 1);