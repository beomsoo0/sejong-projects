t = [0 0.3 0.8 1.1 1.6 2.3];
y = [0.6 0.67 1.01 1.35 1.47 1.25];
figure(1)
plot(t,y,'o');
hold on
title('Plot of y Versus t');
p  = polyfit( t, y, 2 );
x = linspace(0, 3, 100);
yy = polyval(p, x);
plot(x, yy, '-')
pd = polyder( p );
rd = roots( pd );
xm = [ x(1), x(end), rd' ];
ym = polyval( p, xm )
[mm, mi] = sort( ym );
mi
plot( xm, ym, 'x', 'MarkerFaceColor', 'k' );