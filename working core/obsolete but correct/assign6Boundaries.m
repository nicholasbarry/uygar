function L = assign6Boundaries(L, bbVol)
% ASSIGN EACH VOXEL ON THE WATERSHED BOUNDARY TO A 6-NEIGHBOR OBJECT (INCLUDING BACKGROUND) BASED ON COLOR
% WATERSHED DOMAINS MUST BE CALCULATED BY 6-CONNECTIVITY

voxelCount = numel(L);
boundaries = find(L==0); % linear indices 
newBoundaryAssignments = zeros(size(boundaries));

translation_matrix  = fliplr(combvec([-1,0,1],[-1,0,1],[-1,0,1])');translation_matrix(ceil(size(translation_matrix,1)/2),:)=[];
neighborhood_vector = sum(repmat([size(bbVol,1),size(bbVol,1)*size(bbVol,2),1],[size(translation_matrix,1),1]) .* translation_matrix,2);
shift_by_channel    = voxelCount*(0:size(bbVol,4)-1); % 1 x numChannels vector containing multiples of the number of voxels in each 3D stack

[foo, bar] = meshgrid(boundaries,neighborhood_vector);
validIdxs = foo+bar;

iterCount = 1;
while ~isempty(boundaries)
    validIdxs(L(validIdxs)==0)       = -1; % BOUNDARY VOXELS ARE INELIGIBLE
    validIdxs(validIdxs>voxelCount)  = -1; % index above range
    parfor kk = 1:numel(boundaries)
        validIdx                       = validIdxs(:,kk);
        validIdx(validIdx<1)           =[]; % index below range
%         validIdx(validIdx>voxelCount)  =[]; % index above range
%         validIdx(L(validIdx)==0)       =[]; % BOUNDARY VOXELS ARE INELIGIBLE
        
        if ~isempty(validIdx)
%             validVal                   = bbVol(repmat(shift_by_channel,[numel(validIdx),1]) + repmat(validIdx,[1 size(bbVol,4)])); % validVal has shape numel(validIdx) x size(bbVol,4); a 2D array in which each column is the list of values for those linear indices in that color
%             thisVal                    = bbVol(shift_by_channel + thisVoxIdx); % val is the val of the pixel in the volume of thisVolIdx for each color channel
%             allNormSq                  = sum((validVal - repmat(thisVal, [numel(validIdx), 1])).^2, 2); % normalizing the neighbors by the center voxel, squaring, then summing along the rows
%             [~,pos]                    = min(allNormSq); % the indices of the minimum of the normed values
            [~,pos]                    = min(sum((bbVol(repmat(shift_by_channel,[numel(validIdx),1]) + repmat(validIdx,[1 size(bbVol,4)])) - repmat(bbVol(shift_by_channel + thisVoxIdx), [numel(validIdx), 1])).^2, 2)); % the indices of the minimum of the normed values
            newBoundaryAssignments(kk) = L(validIdx(pos)); % isn't this potentially assigning a vector to a 1x1 spot?
        end
    
    end
    
    L(boundaries) = newBoundaryAssignments;
    boundaries = find(L==0);
    newBoundaryAssignments = zeros(size(boundaries));
    iterCount = iterCount+1;
    
end

fprintf('\nassign6boundaries converged after %d iterations.\n\n',iterCount)

end