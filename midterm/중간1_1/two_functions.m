clc
clear
x = [-2:0.01:4];
y = x.^3-2*x.^2-10*(sin(x)).^2-exp(0.9*x);
yd = 3*x.^2-4*x-20*sin(x).*cos(x)-0.9*exp(0.9*x);
plot(x, y)
hold on
plot(x, yd, '--g')
xlabel('x-->');
ylabel('y-->');
legend('f(x)', "f'(x)");
title('f(x)=x^3-2x^2-10sin^2x-e^(0.9x)');
hold off
