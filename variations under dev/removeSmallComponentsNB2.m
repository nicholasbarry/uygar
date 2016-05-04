function [L2] = removeSmallComponentsNB2(L2, opts)
%{
This differs from the previous version by filtering out on ALL components,
not just the connected ones. To do this, it is passed not a binary mask
with 0s in the background and 1s wherever there is any watershed region,
but the full array of watershed regions (will the background be a problem?)
%}
numZeros          = numel(find(L2==0));
L2size            = size(L2);
minVoxelCount     = opts.minVoxelCount;
zAnisotropy       = opts.zAnisotropy;
moiRatioThreshold = opts.moiRatioThreshold;


regions           = unique(L2);
h                 = histogram(L2,regions);
counts            = h.Values;

smallComponents   = regions(counts < opts.minVoxelCount); %smallComponents is now the unique IDs of each region with fewer than minVoxelCount voxels
toRemove          = false(size(smallComponents));

if opts.precise

    parfor kk = 1:numel(smallComponents)
        
        [xx, yy, zz]       = ind2sub(L2size, find(L2==regions(kk)));
        zz                 = zz * zAnisotropy; % zAnisotropy = zVoxelLength/xyVoxelLength
        xyz                = [xx-mean(xx), yy-mean(yy), zz-mean(zz)];
        
        % FIND THE INERTIA TENSOR
        xyz_sq             = xyz.^2;
        weights            = ones(size(xyz,1),1); % what is this for?
        inertiaTensor      = zeros(3);
        inertiaTensor(1,1) = sum(weights .* (xyz_sq(:,2) + xyz_sq(:,3)));
        inertiaTensor(2,2) = sum(weights .* (xyz_sq(:,1) + xyz_sq(:,3)));
        inertiaTensor(3,3) = sum(weights .* (xyz_sq(:,1) + xyz_sq(:,2)));
        inertiaTensor(1,2) = -sum(weights .* xyz(:,1) .* xyz(:,2));
        inertiaTensor(1,3) = -sum(weights .* xyz(:,1) .* xyz(:,3));
        inertiaTensor(2,3) = -sum(weights .* xyz(:,2) .* xyz(:,3));
        inertiaTensor      = inertiaTensor + triu(inertiaTensor,1)';

        % FIND THE MOMENT OF INERTIA FOR EACH PRINCIPAL AXIS
        [~, evMatrix]      = eig(inertiaTensor);
        
        % IF THE RATIO OF THE LARGEST TO SMALLEST EIGENVALUES IS SMALL, THEN THE SUPERVOXEL IS NOT ELONGATED ENOUGH
        % IT MAY NOT BE A DENDRITE (MAY BE AN ORGANELLE) -- mCherry information can be useful here.
        toRemove(kk) = (evMatrix(3,3)/evMatrix(1,1))<moiRatioThreshold;
        
    end
    size(toRemove)
    size(smallComponents)
    toRemove = smallComponents(toRemove);

else
    
    toRemove = smallComponents;

end

% REMOVE
L2(ismember(L2,toRemove)) = 0;

% REPORT
fprintf('\n%d components identified. \n%d components (%d / %d voxels) removed.... \n%d components remain.\n',...
        numel(regions),numel(toRemove),numel(find(L2==0))-numZeros,numel(L2)-sum(L2(:)~=0),numel(regions)-numel(toRemove))

end