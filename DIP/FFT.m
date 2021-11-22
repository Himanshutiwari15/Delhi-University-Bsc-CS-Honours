% Perform frequency domain filtering on an  image.
% a) Apply FFT on given image in MATLAB.

%cleaning
clc;
clear all;
close all;

%Reading an image
pkg load image;
img1 =imread("C:/Users/91962/Desktop/Final SEM Practicals/DIP/boat.png");

%Original image
subplot(2,2,1);
imshow(img1);
title("Original Image");
result=fftshift(fft2(img1));

%FFT image
subplot(2,2,3);
imshow(result);
title("FFT Image");
