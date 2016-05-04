function [mask] = removeSmallComponentsNB(mask, opts)

numZeros = numel(find(mask==0));
CC = bwconncomp(mask, 26);
moiRatioThreshold = opts.moiRatioThreshold;

if opts.precise
    
    componentSizes  = cellfun(@numel, CC.PixelIdxList); % list of how many voxels are in each connected component
    smallComponents = find(componentSizes<opts.minVoxelCount); % indices of the above list for which the connected component has fewer than the mininum number of voxels
    toRemove        = false(numel(smallComponents), 1);
    
    parfor kk = 1:numel(smallComponents)
        
        [xx, yy, zz]       = ind2sub(size(mask), CC.PixelIdxList{smallComponents(kk)});
        xyz                = [xx-mean(xx), yy-mean(yy), zz-mean(zz)];
        %zz                 = zz * opts.zAnisotropy; % zAnisotropy = zVoxelLength/xyVoxelLength
        % FIND THE INERTIA TENSOR
        weights            = ones(size(xyz,1),1);
        inertiaTensor      = zeros(3);
        inertiaTensor(1,1) = sum(weights .* (xyz(:,2).^2 + xyz(:,3).^2));
        inertiaTensor(2,2) = sum(weights .* (xyz(:,1).^2 + xyz(:,3).^2));
        inertiaTensor(3,3) = sum(weights .* (xyz(:,1).^2 + xyz(:,2).^2));
        inertiaTensor(1,2) = -sum(weights .* xyz(:,1) .* xyz(:,2));
        inertiaTensor(1,3) = -sum(weights .* xyz(:,1) .* xyz(:,3));
        inertiaTensor(2,3) = -sum(weights .* xyz(:,2) .* xyz(:,3));
        inertiaTensor      = inertiaTensor + triu(inertiaTensor,1)';

        % FIND THE MOMENT OF INERTIA FOR EACH PRINCIPAL AXIS
        [~, evMatrix]      = eig(inertiaTensor);
        % IF THE RATIO OF THE LARGEST TO SMALLEST EIGENVALUES IS SMALL, THEN THE SUPERVOXEL IS NOT ELONGATED ENOUGH
        % IT MAY NOT BE A DENDRITE (MAY BE AN ORGANELLE) -- mCherry information can be useful here.
        toRemove(kk) = evMatrix(3,3)/evMatrix(1,1) < moiRatioThreshold;
        
    end
    toRemove = smallComponents(toRemove);

    % REMOVE
    for kk = 1:numel(toRemove)
        mask(CC.PixelIdxList{toRemove(kk)}) = 0;
    end
    
    fprintf('\n%d components identified. \n%d components (%d / %d voxels) removed.... \n%d components remain.\n',...
            CC.NumObjects,length(toRemove),numel(find(mask==0))-numZeros,numel(mask),CC.NumObjects-length(toRemove))
    fprintf('\nSetting minVoxelCount = %d removes %d out of %d total components.\n',opts.minVoxelCount,length(toRemove), CC.NumObjects);
else
    for kk=1:CC.NumObjects
        if numel(CC.PixelIdxList{kk}) < opts.minVoxelCount
            mask(CC.PixelIdxList{kk}) = 0;
        end
    end
end

end