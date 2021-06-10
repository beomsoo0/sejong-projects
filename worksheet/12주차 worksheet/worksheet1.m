clear
clc

p = [1 2 -13 -14 24];
x = -5:0.1:5;
figure(1);
plot(x, polyval(p,x));
