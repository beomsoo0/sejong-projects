clear
clc
fg_data1 = imread('eight.tif');
imshow(fg_data1)
data_255 = 255 * ones(size(fg_data1));




%8
A = [2 1 1; 1 2 1; 1 1 2];
b = [16; 9; 3];
x1 = inv(A) * b;
x2 = A^-1 * b;
x1 == x2

%10
x = [-6:0.01:6];
y = sin(x) + x.^2 + 2*x + 4;
plot(x, y)