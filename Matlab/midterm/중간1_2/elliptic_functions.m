clear, clc
syms x y
S = ((x-2)^2) / 10^2 + ((y-3)^2) / 4^2 - 1;
fplot(S, [-10, 15]);
xlabel('x-->')
ylabel('y-->')
title('Ellipse with center (2,3), a=10 and b=4');