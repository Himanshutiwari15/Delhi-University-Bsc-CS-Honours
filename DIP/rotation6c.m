% Perform following geometric transformation of image.
% c) To perform rotation of an image

%cleaning
clc;
clear all;
close all;

%Reading an image
pkg load image;
img1 =imread("C:/Users/91962/Desktop/Final SEM Practicals/DIP/boat.png");
i =imrotate(img1,[45]);

%Original image
subplot(3,1,1);
imshow(img1);
title("Original Image");

subplot(3,1,2);
imshow(i);
title("Rotate Image");