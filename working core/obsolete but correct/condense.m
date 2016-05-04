function [L3] = condense(L3)

oldval = unique(L3); 
newval = 1:numel(oldval);
newL = L3;
%bite = floor(numel(newval)/100);
%count = int8(numel(newval));
for k = 1:numel(newval)
   newL(L3 == oldval(k)) = newval(k);
%   if mod(k,bite)==0;fprintf('\n%d out of %d filtrations done.\n',int8(k),count);end
end
L3 = newL;

end