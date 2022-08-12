clear
clc
syms x
y1 = x^2 + x + 1;
y2 = -3*x + 6;
figure(1)
fplot(y1, [-2, 2])
figure(2)
fplot(y2, [-2, 2])