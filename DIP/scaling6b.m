% Perform following geometric transformation of image.
% b) To perform scaling of an image

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
j =imresize(img1,[400,400]);

subplot(2,2,2);
imshow(j);
title("Resized Image");
