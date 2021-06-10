clear
clc
%1
syms n
limit(((-3+2*n)/(-7+3*n))^4, n, inf)
limit(((1+n)/n)^(1/n), n, inf)
clear
%2
syms n
f1 = n / (2^n);
f2 = (n+1) / (2^(n+1));
limit(f2/f1, n, inf)
clear
%3
syms x
diff(log(sin(2*x)))
clear
%4
syms x y
f = sin(x*y) + cos(x*y^2);
diff(f,x)
diff(f,y)
%5
diff(f,x,2)
clear
%6
syms x
int(1/(x^2-1))
clear
%7
syms a b x
int(a * log(1 + b*x), x, 0, 1)
clear
%8
syms y a
diffeq = 'Dy = a * y';
dsolve(diffeq)
%9
dsolve(diffeq, 'y(0) = 0')
%10
clear
syms a y
diffeq = 'D2y = -a^2 * y';
dsolve(diffeq, 'y(0)=1', 'Dy(pi/a) = 0')