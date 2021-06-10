clear clc
syms a b c d
y1 = a*(-2.6)^3+b*(-2.6)^2+c*(-2.6)+d == -68;
y2 = a*(0.5)^3+b*(0.5)^2+c*(0.5)+d == 5.7;
y3 = a*(1.5)^3+b*(1.5)^2+c*(1.5)+d == 4.9;
y4 = a*(3.5)^3+b*(3.5)^2+c*(3.5)+d == 88;
[as bs cs ds] = solve(y1, y2, y3, y4)
fprintf("The equation is f(x) = %.3fx^3 + %.3fx^2 + %.3fx + %.3f\n", as, bs, cs, ds)