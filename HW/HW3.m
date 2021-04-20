clear
clc
syms x y
f1 = (x-1)^2 / 6^2 + y^2 / 3^2 == 1;
f2 = (x+2)^2 / 2^2 + (y-5)^2 / 4^2 == 1;
ezplot(f1, [-10, 10, -4, 10])
axis equal
hold on
ezplot(f2, [-10, 10, -4, 10])
hold off
[xs, ys] = solve(f1, f2);