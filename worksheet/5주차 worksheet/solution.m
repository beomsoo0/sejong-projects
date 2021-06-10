clear
clc
%1
r = input('반지름을 입력하세요 : ')
fprintf('입력하신 반지름은: %d[cm]입니다.\n', r)
fprintf('해당 원의 둘레는: %f[cm]이고, 면적은 : %f[cm^2]이다.\n', 2*pi*r, pi*r^2)
%2
%r = input('반지름을 입력하세요 : ')
%disp('입력하신 반지름은: ', r, '[cm]입니다.\n')
%disp('해당 원의 둘레는: ',num2str(2*pi*r), '[cm]이고, 면적은 : ', num2str(pi*r^2), '[cm^2]이다.\n')

%3

%4
data = imread('eight.tif');
imshow(data)