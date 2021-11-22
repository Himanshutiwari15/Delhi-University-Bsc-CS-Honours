% Perform following geometric transformation of image.
% d) To perform shrinking of an image

%cleaning
clc;
clear all;
close all;

%Reading an image
pkg load image;
img1 =imread("C:/Users/91962/Desktop/Final SEM Practicals/DIP/boat.png");
disp('Input Image ==> girl.jpg');
f =input("Enter theshrinking factor of the image");

s=size(img1);
s1=s/f;
k=1;
l=1;
for i=1:s1
    for j=1:s1
        B(i,j)=img1(k,l);
        l=l+f;
    end
    l=1;
    k=k+f;
end


%Original image
figure;
imshow(img1);
title("Original Image");

%shrinked image
figure;
imshow(B);
title("Shrinked Version");