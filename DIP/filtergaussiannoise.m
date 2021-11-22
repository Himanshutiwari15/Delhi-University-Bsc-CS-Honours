pkg load image;
pkg load statistics;
I = imread("D:/ansh_bsc/sem5/DIP Pract/labrador.jpg");
I = uint8(I);
I=double(I);
S_=size(I);
I = rgb2gray(I);
subplot(2,2,1);
imshow(I); 
title('Input Image');
J = imnoise(I,'gaussian');
subplot(2,2,2);
imshow(J);
title("Input Image with Gaussian Noise");
J = double(J);
Mask=7;
for i=1:S_(1)
    j=1;
    while(j<S_(2)-Mask)
        T(1:Mask)=J(i,j:j+(Mask-1));
        Data=harmmean(J);
        J(i,j+1)=Data(i,j);
        J=j+1;
    end;
end;
subplot(2,2,3);
imshow(J);
title("Filtered Image");



