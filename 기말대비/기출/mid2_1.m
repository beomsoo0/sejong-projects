clear clc
x = [-8:0.1:12];
y1 = sqrt(16 - 4/25*(x-2).^2) + 3;
y2 = -sqrt(16 - 4/25*(x-2).^2) + 3;
plot(x,y1,x,y2)
axis([-10 15 -6 12])
xlabel('x-->')
ylabel('y-->')
title('Ellipse with center (2,3), a=10 and b=4')

