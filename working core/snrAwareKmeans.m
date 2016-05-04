function [index] = snrAwareKmeans(colorData, clusterCount, opts_fkmeans)
% what is allCentroids used for? why bother returning it from fkmeans, why preallocate it?

cc                                       = size(colorData, 1);
opts_irbleigs.K                          = clusterCount;

index                                    = zeros(cc, 1);
distortion                               = 1e60;
%allCentroids                             = zeros(opts_irbleigs.K, size(colorData, 2));

for kk = 1:opts_fkmeans.repeats
    [myIndex, ~, myDistortion] = simple_fkmeans(colorData, opts_irbleigs.K, opts_fkmeans);
    %[myIndex, myCentroids, myDistortion] = fkmeans(colorData, opts_irbleigs.K, opts_fkmeans); % which is it?
    if sum(myDistortion)<distortion
        distortion                       = sum(myDistortion);
        index                            = myIndex;
        %allCentroids                     = myCentroids;
    end
end
