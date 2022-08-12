phi = (0:5)*4*pi/5 + pi/2;
x   = cos(phi);  y = sin(phi);
plot( x, y, 'linewidth', 2 );
grid on; xlabel('x'); ylabel('y');
title('Pentagram'); axis equal;