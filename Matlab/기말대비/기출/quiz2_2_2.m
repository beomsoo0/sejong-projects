clear
clc
syms x
y1 = x^2 + x + 1;
y2 = -3*x + 6;
solve(y1 - y2)
y = subs(y1, x, 1)