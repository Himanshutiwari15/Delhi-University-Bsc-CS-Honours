
pkg load image;
img1 =imread("C:/Users/91962/Desktop/Final SEM Practicals/DIP/boat.png");
[row, col] =size(img1);
tx =input("Enter the translation parameters tx=");
ty =input("Enter the translation parameters ty=");

for i=1:row-tx
    for j=1:col-ty
        T(i+tx,j+ty)=img1(i,j);
    end
end

imshow(img1),figure,imshow(T);
