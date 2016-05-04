function [L3] = condense_spmd(L3)

oldval = unique(L3);
newval = 1:numel(oldval);
newL = L3;
spmd
    
    newL1 = codistributed(newL,codistributor1d(3));
    L31   = codistributed(L3,codistributor1d(3));
    
    for k = 1:numel(newval)
        newL1(L31 == oldval(k)) = newval(k);
    end
    
end

L3 = gather(newL1);

end