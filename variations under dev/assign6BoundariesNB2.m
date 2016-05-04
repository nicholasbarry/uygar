function L = assign6BoundariesNB2(L, bbVol)
% assigns to every watershed boundary voxel the color of the nearest voxel in colorspace by squared difference
voxelCount = numel(L);
boundaries = find(L==0); % linear indices of watershed boundary regions
newBoundaryAssignments = zeros(size(boundaries));
translation_matrix = [ ...
    -1    -1    -1; ...
    -1    -1     0; ...
    -1    -1     1; ...
    -1     0    -1; ...
    -1     0     0; ...
    -1     0     1; ...
    -1     1    -1; ...
    -1     1     0; ...
    -1     1     1; ...
     0    -1    -1; ...
     0    -1     0; ...
     0    -1     1; ...
     0     0    -1; ...
     0     0     1; ...
     0     1    -1; ...
     0     1     0; ...
     0     1     1; ...
     1    -1    -1; ...
     1    -1     0; ...
     1    -1     1; ...
     1     0    -1; ...
     1     0     0; ...
     1     0     1; ...
     1     1    -1; ...
     1     1     0; ...
     1     1     1];
% translation_matrix  = fliplr(combvec([-1,0,1],[-1,0,1],[-1,0,1])');translation_matrix(ceil(size(translation_matrix,1)/2),:)=[];
% a = {[-1,0,1],[-1,0,1],[-1,0,1]};v=cell(3,1);[v{:}] = ndgrid(a{:});res = reshape(cat(4,v{:}),[],3);translation_matrix(ceil(size(res,1)/2),:)=[];

neighborhood_vector = sum(repmat([size(bbVol,1),size(bbVol,1)*size(bbVol,2),1],[size(translation_matrix,1),1]) .* translation_matrix,2);
shift_by_channel    = voxelCount*(0:(size(bbVol,4)-1)); % 1 x numChannels vector containing multiples of the number of voxels in each 3D stack

[foo, bar]          = meshgrid(boundaries,neighborhood_vector);
%validIdxs           = gpuArray(foo+bar);
validIdxs           = (foo+bar);

%validIdxs((validIdxs>voxelCount) | (validIdxs<1)) = 1;keepIdxs            = validIdxs~=1 & validIdxs(L(validIdxs)~=0); % losing a few voxels of info here 
%keepIdxs            = (validIdxs<=voxelCount) & (validIdxs>0) & (validIdxs(L(validIdxs)~=0));

inRange = (validIdxs<=voxelCount) & (validIdxs>0);
save1s = validIdxs==1;
validIdxs(~inRange) = 1;
keepIdxs = validIdxs~=1 & (L(validIdxs)~=0); % losing a few voxels of info here 
keepIdxs(save1s) = 1; 
disp('purified')


iterCount = 1;
tic
while ~isempty(boundaries)
    
    parfor kk = 1:numel(boundaries)
        thisVoxIdx                     = boundaries(kk);
%         validIdx                       = validIdxs(:,kk);
%         validIdx(validIdx<1)           =[]; % index below range
%         validIdx(validIdx>voxelCount)  =[]; % index above range
%         validIdx(L(validIdx)==0)       =[]; % BOUNDARY VOXELS ARE INELIGIBLE
        validIdx                       = validIdxs(keepIdxs(:,kk),kk);

        if ~isempty(validIdx) 
%             validVal                   = bbVol(repmat(shift_by_channel,[numel(validIdx),1]) + repmat(validIdx,[1 size(bbVol,4)])); % validVal has shape numel(validIdx) x size(bbVol,4); a 2D array in which each column is the list of values for those linear indices in that color
%             thisVal                    = bbVol(shift_by_channel + thisVoxIdx); % val is the val of the pixel in the volume of thisVoxIdx for each color channel
%             allNormSq                  = sum((validVal - repmat(thisVal,[numel(validIdx), 1])).^2, 2); % normalizing the neighbors by the center voxel, squaring, then summing along the rows (colors)
%             [~,pos]                    = min(allNormSq); % the index of the minimum of the normed distances (technically could be indices but impossible odds)
            [~,pos]                    = min(sum((bbVol(repmat(shift_by_channel,[numel(validIdx),1]) + repmat(validIdx,[1 size(bbVol,4)])) - repmat(bbVol(shift_by_channel + thisVoxIdx), [numel(validIdx), 1])).^2, 2)); % the indices of the minimum of the normed values
            %newBoundaryAssignments(kk) = L(validIdx(pos)); % shouldn't assign by L inside the loop! just keep a record of the index and do it after
            newBoundaryAssignments(kk) = validIdx(pos);
        end
    end
    
    %L(boundaries) = newBoundaryAssignments;
    L(boundaries) = L(newBoundaryAssignments);
    boundaries = find(L==0);
    newBoundaryAssignments = zeros(size(boundaries));
    iterCount = iterCount+1;
    
end
toc
fprintf('\nassign6boundaries converged after %d iterations.\n\n',int8(iterCount))

end