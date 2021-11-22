% Perform following logical operations of image.
% b) OR operation between two images

%cleaning
clc;
clear all;
close all;

%Reading an image
pkg load image;
img1 =imread("C:/Users/91962/Desktop/Final SEM Practicals/DIP/boat.png");
img2 =imread("C:/Users/91962/Desktop/Final SEM Practicals/DIP/lena.png");
img1 =im2bw(img1);
img2 =im2bw(img2);
im1 =imresize(img1,[200 400]);
im2 =imresize(img2,[200 400]);
result =or(im1,im2);

%Binary
subplot(3,1,1);
imshow(img1);
title("FIRST IMAGE IN BINARY");

%Binary
subplot(3,1,2);
imshow(img2);
title("SECOND IMAGE IN BINARY");

%OR
subplot(3,1,3);
imshow(result);
title("IMAGE AFTER LOGICAL OR OPERATION");
