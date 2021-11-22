###Program to find low pass filtered 
###version of matrix as well as image.
clear;
clc;
clf;

pkg load image;
i =imread("C:/Users/91962/Desktop/Final SEM Practicals/DIP/boat.png");
# pass image through low pass filter

subplot(1,2,1)
imshow(i)

f=ones(3,3)/9;
x=filter2(f,i,'same');
x
subplot(1,2,2)
imshow(x/255)