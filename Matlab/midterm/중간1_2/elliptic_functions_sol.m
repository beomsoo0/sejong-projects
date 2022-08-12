clear, clc
x = -8:0.1:12;
y1 = 3 + sqrt(16-4*(x-2).^2/25);
y2 = 3 - sqrt(16-4*(x-2).^2/25);
plot(x, y1, x, y2);
axis([-10 15 -5 5]);
axis equal
xlabel('x-->');
ylabel('y-->');
title('Elipse with center (2,3), a=10 and b=4');