syms x y
f1 = y == x^2 + x + 1;
f2 = y == -3*x + 6;
[xs, ys] = solve(f1, f2)
y = subs(f1, x, 1)
%-2<=x<=2 이므로 x = 1, y = 3