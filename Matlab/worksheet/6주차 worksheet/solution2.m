clear
clc
x = [0: 0.01: 2*pi];
y1 = sin(x);
y2 = cos(x);
plot(x, y1, x, y2)
ylabel('Magnitude')
xlabel('Angle in Radian')
title('Sin and Cos graph')
text(3, 0.7, 'sin(x)')
text(4.5, 0.7, 'cos(x)')
legend('sin(x)','cos(x)');

subplot(2, 2, 1);
plot(x, y1);

subplot(2, 2, 2);
plot(x, y2);