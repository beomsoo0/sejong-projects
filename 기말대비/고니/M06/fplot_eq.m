% Equivalent plot script for
% fplot('x^2+4*sin(2*x)-1', [-3 3], 'r-')
x = -3:0.01:3;
y = x.^2+4*sin(2*x)-1;
figure(1), plot(x,y,'r-');
minY = floor(min(y));
maxY = ceil(max(y));
axis([-3 3 minY maxY]);
