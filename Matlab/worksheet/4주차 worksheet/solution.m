clear
clc
%1
syms x a b c
eqn1 = a * x^2 + b * x + c
%2
clear
%3
syms x
eqn2 = expand((x-2)*(x+3)*(x-3))
%4
factor(eqn2)
clear
%5
syms P r t P0
%E3 = P==P0*exp(r*t)
%simplify(E3, t)
clear
%6
syms x
y = (2*(x+3)^2)/(x^2+6*x+9)
simplify(y)
clear
%7
syms x y z
one = 3*x + 2*y - z == 10
two = -x + 3*y + 2*z == 5
three = x - y - z == -1
[xs ys zs] = solve(one, two, three)