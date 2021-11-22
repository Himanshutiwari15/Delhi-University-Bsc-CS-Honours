% Perform following logical operations of image.
% d) To perform NOT operation of two images 

%cleaning
clc;
clear all;
close all;

%Reading an image
pkg load image;
img1 =imread("C:/Users/91962/Desktop/Final SEM Practicals/DIP/boat.png");
img1 =im2bw(img1);
result =not(img1);

%Binary
subplot(2,1,1);
imshow(img1);
title("IMAGE IN BINARY");


%INTERSECTION
subplot(2,1,2);
imshow(result);
title("IMAGE AFTER NOT OPERATION");
