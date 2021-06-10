clear
clc

row_vector = [1 5 10 11 17 21 17]

column_vector = row_vector'

A = [1 5; 9 11]

a = [1 2; 3 4; 5 6]
size(a)
size(a,2)

b = row_vector(1:2:end)

a = linspace(1,101,5)

c_man = imread('cameraman.tif');
imshow(c_man);
size(c_man)
% 행렬

c_man(19, 177:255) = 0;
imshow(c_man)

c_man(19, 177:255) = 255;
imshow(c_man)