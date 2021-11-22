% c) Remove Salt and Pepper Noise

%cleaning
clc;
clear all;
close all;

%Reading an image
pkg load image;
I = imread("C:/Users/91962/Desktop/Final SEM Practicals/DIP/boat.png");
I = uint8(I);
subplot(2,2,1);
imshow(I);
title('Input Image');

%inserting noise 
J = imnoise(I,'salt & pepper',0.05);
subplot(2,2,2);
imshow(J);
title('Input Image with Salt and Pepper Noise');

%Implementing mean filter
J = double(J);
filtered_mean_img = zeros(size(J));
for i = 1:size(J, 1) - 2
for j = 1:size(J, 2) - 2
filtered_mean_img(i+1,j+1) = sum(sum(J(i:i+2, j:j+2)));
K(i+1,j+1) = (filtered_mean_img(i+1,j+1) / 9);
endfor

endfor
K = uint8(K);
subplot(2,2,3);
imshow(K);
title('Filtered Image with Mean Filter');

%Implementing median filter
modifyJ=zeros(size(J)+2);

B = zeros(size(J));
for x=1:size(J,1)
for y=1:size(J,2)
modifyJ(x+1,y+1)=J(x,y);
end
end
for i= 1:size(modifyJ,1)-2
for j=1:size(modifyJ,2)-2
window=zeros(9,1);
inc=1;
for x=1:3
for y=1:3
window(inc)=modifyJ(i+x-1,j+y-1);
inc=inc+1;
end
end
med=sort(window);
B(i,j)=med(5);

end
end
B = uint8(B);
subplot(2,2,4);
imshow(B);
title('Filtered Image with Median Filter');