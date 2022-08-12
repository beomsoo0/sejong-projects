%% Data Points
x1 = [  32  33  32  29  20  88  39  0 ];
y1 = [ 323 321 319 313 246  72  0.1 0 ];
 
%% Interpolation between points
N1 = 40;
P  = length(x1);
n  = 0:P-1;
ni = linspace(0, P-1, N1);
xc = interp1( n, x1, ni, 'pchip' );
yc = interp1( n, y1, ni, 'pchip' );
figure(1);
h = plot( x1, y1, 'bo', xc, yc, 'b-' );
set(h(1), 'MarkerFaceColor', 'b');
grid on; axis equal; hold on;
 
%% Interpolation between heights
N  = 255;
x0 = xc;
y0 = yc;
y  = linspace( min(y0), max(y0), N );
x  = interp1( y0, x0, y, 'pchip');
plot( x0, y0, 'ro', x, y, 'r-' );
hold off;
 
%% Korean Traditional Bottle
[X, Y, Z] = cylinder( x, 20);
figure(2);
surf(X, Y, 300*Z, 'linestyle', 'none');
axis equal;
colormap('jet'); % Try colormapeditor; 
