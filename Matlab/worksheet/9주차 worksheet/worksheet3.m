x=0:pi/180:2*pi;
for y=0:pi/2:pi/2
x1=cos(x); (1)
x2=sin(x); (2)
plot(x1,'b-');
axis([0 360 -1 1])
hold
plot(x2,'r:');
axis([0 360 -1 1])
title('Sin and Cosin');
grid on;
