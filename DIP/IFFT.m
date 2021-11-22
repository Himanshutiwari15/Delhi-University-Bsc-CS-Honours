% Perform frequency domain filtering on an  image.
% a) Apply IFFT to recontstruct image 

%cleaning
clc;
clear all;
close all;

%Reading an image
pkg load image;
img1 =imread("C:/Users/91962/Desktop/Final SEM Practicals/DIP/boat.png");
img =rgb2gray(img1);

%Original image
subplot(1,3,1);
imshow(img1);
title("Original Image");
li=1;
set(gcf,'Position',get(0,'ScreenSize'));
F =fft2(double(img));
F_Mag =abs(F);
F_Phase =exp(li*angle(F));


%Reconstruction
I_Mag =log(abs(ifft2(F_Mag*exp(1i*0)))+1);
I_Phase =ifft2(F_Phase);

%Calculating limits of plotting
I_Mag_min = min(min(abs(I_Mag)));
I_Mag_max = max(max(abs(I_Mag)));
I_Phase_min = min(min(abs(I_Phase)));
I_Phase_max = max(max(abs(I_Phase)));


%Reconstructed Image only by Magnitude
subplot(1,3,2);
imshow(abs(I_Mag),[I_Mag_min,I_Mag_max]);
colormap gray;
title("Reconstructed Image only by Magnitude");

%Reconstructed Image only by Phase
subplot(1,3,3);
imshow(abs(I_Phase),[I_Phase_min,I_Phase_max]);
colormap gray;
title("Reconstructed Image only by Phase");
