function f = Fibo(n)
% Fibonacci number generator
p = 0.5*(1+sqrt(5));
q = 0.5*(1-sqrt(5));
f = (p^n-q^n)/sqrt(5);
