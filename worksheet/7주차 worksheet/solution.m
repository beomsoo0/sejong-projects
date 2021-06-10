clc
clear
%1
x = [-51:22];
x = x + (x==0)*eps;
y = sin(x) ./ x;
plot(x, y)
clear
%2

