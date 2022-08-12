%
r  = [ -2 0 0 1];
p  = poly(r);
q  = polyder(p);
qr = roots(q);
x  = -2.5:0.01:1.5;
y  = polyval( p, x );
ym = polyval( p, qr );
yd = polyval( q, x );
h  = plot( x, y, 'r-', x, yd, 'b-', qr, ym, 'ro' );
set( h(1), 'LineWidth', 2 );
ylim([-5 5]);
grid on;

