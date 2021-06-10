clear
clc

p = [1 2 -13 -14 24];
x = -5:0.1:5;
figure(1);
plot(x, polyval(p,x));
hold on;

f = [2 2 -2 -2];
fr = roots(f);
fy = polyval(f, fr);
plot(fr, fy, 'ro')
hold on

g = [2 -2];
gr = roots(g);
gy = polyval(g, gr);
plot(gr, gy, 'bo');
hold off