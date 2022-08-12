clear
clc
x = [-2:0.1:4];
y = x.^3 - 2*x.^2 - 10*sin(x).^2 - exp(0.9*x);
y2 = 3*x.^2 - 4*x - 20*cos(x).*sin(x) - 0.9*exp(0.9*x);
figure(1)
plot(x, y)
hold on
plot(x, y2, '--')
xlabel('x-->')
ylabel('y-->')
legend('f(x)', "f'(x)")
title('f(x)=x^3 - 2x^2 - 10sin^2(x) - e^{0.9x}')