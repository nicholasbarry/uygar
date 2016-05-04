function [gradAmplitude] = get_intensity_gradient(numYpixels, numXpixels, numSlices, bbVol)

gradAmplitude = zeros(numYpixels, numXpixels, numSlices);

tmpbb = cat(1,bbVol(1,:,:,:),bbVol);
gradAmplitude = max(gradAmplitude, squeeze(max(abs(diff(tmpbb,1,1)),[],4)) );

tmpbb = cat(2,bbVol(:,1,:,:),bbVol);
gradAmplitude = max(gradAmplitude, squeeze(max(abs(diff(tmpbb,1,2)),[],4)) );

tmpbb = cat(3,bbVol(:,:,1,:),bbVol);
gradAmplitude = max(gradAmplitude, squeeze(max(abs(diff(tmpbb,1,3)),[],4)) );

end