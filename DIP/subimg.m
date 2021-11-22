% b. Subtract one image from other image

%cleaning
clc;
clear all;
close all;

%Reading an first image and displaying it
pkg load image;
I = imread("C:/Users/91962/Desktop/Final SEM Practicals/DIP/boat.png");
a = imresize(I,[400,400]);
figure
imshow(a);
title("First Image");

%Reading an Second image and displaying it
J = imread("C:/Users/91962/Desktop/Final SEM Practicals/DIP/lena.png");
b = imresize(J,[400,400]);
figure
imshow(b);
title("Second Image");

%Subtracting one image from other image
K = imsubtract(a,b);
figure

%Displying Subtracted Image
imshow(K);
title("Subtracted Image");