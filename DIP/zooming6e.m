% Perform following geometric transformation of image.
% e) To perform zooming of an image

% ye ansh bhai yamu tu thik karnaa 
%cleaning
clc;
clear all;
close all;

%Reading an image
pkg load image;
img6 =imread("C:/Users/91962/Desktop/Final SEM Practicals/DIP/boat.png");
[m,n,colormap]=size(img6);
if colormap==3
    x=img6(:,:,1);
    y=img6(:,:,2);
    z=img6(:,:,3);
end

c=[];
k =1;
l =1;
f =input('Enter the replication factor by which the image is to be Zoomed:');
for i=1:m
    for t=1:f
        for j=1:n
            for t=1:f
                if colormap==3
                    c1(k,l)=x(i,j);
                    c2(k,l)=y(i,j);
                    c3(k,l)=z(i,j);
                else
                    c(k,l)=b(i,j);
                end
                l=l+1;
            end
        end
        l=1;
        k=k+1;
    end
end

if colormap==3
    c1(:,:,1)=c1;
    c2(:,:,2)=c2;
    c3(:,:,3)=c3;
end

%Original image
figure;
imshow(img6);
title("Original Image(256,256)");

%Zoomed image
figure;
imshow(c);
title('Zoomed Image(512,512)');
