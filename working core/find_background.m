function [L1] = find_background(L0,unique_regions)

L1 = L0;
counts = zeros(size(unique_regions));
parfor kk = 1:numel(unique_regions)
    counts(kk) = nnz(L1 == unique_regions(kk));
end

% find the largest unique region. this is probably the background.
[~, background_id] = max(counts);

% find all the voxel indices of region 1
tmp = L1==1;

% assign the background voxels to 1
L1(L1==background_id) = 1;

% assign the old background_id to what used to be region 1.
L1(tmp) = background_id;
% now we have effectively swapped the labels for region1 and whatever region had the largest number of voxels in it.


%% could also just threshold by identifying first peak in the distribution of intensities collapsed from normalized bbVol
%{
%choose threshold
collapse  = sum(bbVol,4); %sum the normalized intensity across all channels
h         = histogram(collapse(:)); % calculate the histogram of the distribution of these intensities
[~,locs]  = findpeaks(h.Values); % find all the peaks in that frequency distribution
threshold = h.Data(locs(1)); % set the threshold to be the intensity value in the very first (leftmost, closest to zero) peak 
% actually, even this seems way too low in the real data

% L1: 0 = boundary, 1 = background, 2...max(L1(:)) = watershed regions
L1        = L0+1;
L1(collapse < threshold) = 1; % set every voxel whose intensity is below the threshold to background (although this may disrupt some watershed regions; perhaps it should be before the watershed call?)
L1(L0==0) = 0; % repaint the boundaries


%}

end