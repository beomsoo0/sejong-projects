clear
clc
syms x
y1 = x^3 - 2*x^2 - 10*sin(x)^2 - exp(0.9*x);
y2 = diff(y1);
figure(1)
fplot(y1, [-2, 4])
hold on
fplot(y2, [-2, 4], '--')
xlabel('x-->')
ylabel('y-->')
legend('f(x)', "f'(x)")
title('f(x)=x^3 - 2x^2 - 10sin^2(x) - e^{0.9x}')