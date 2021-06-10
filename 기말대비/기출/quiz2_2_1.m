clear
clc
syms x y
eqns = [y==x^2+x+1, y==-3*x+6];
vars=[x, y];
[xs, ys] = solve(eqns, vars);
xs
ys
