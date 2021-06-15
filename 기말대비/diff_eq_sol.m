syms s t Y
f = 2*sin(t);
F = laplace(f,t,s);
Y1 = s*Y - 1;
Y2 = s*Y1 - 5;
Sol = solve(Y2 + 3*Y1 + 2*Y - F, Y);
sol = ilaplace(Sol, s, t);
figure;
ezplot(sol, [0, 20])