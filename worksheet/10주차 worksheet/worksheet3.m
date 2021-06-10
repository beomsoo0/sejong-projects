clear
clc
figure(1);
x = -5:0.1:0;
plot(x, sqrt(x.^2+1), 'b')
hold on
x = 0:0.1:10;
plot(x, 3*x+1, 'b')
hold on
x = 10:0.1:15;
plot(x, 9*sin(5*x-50)+31, 'b')
hold off