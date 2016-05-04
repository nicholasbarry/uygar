function [counts] = get_unique_counts(a,uniques)

counts = zeros(numel(uniques),1);

for i = 1:numel(uniques)
    counts(i) = nnz(a==uniques(i));
end


end