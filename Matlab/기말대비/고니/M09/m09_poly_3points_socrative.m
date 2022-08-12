y = [1 -1 2]';
A = [1 -1 1; 0 0 1; 4 2 1];
p = A \ y;
x = -2:0.01:2.5;
y1 = polyval(p, x );
figure(1);
plot( x, y1, 'b-', [-1 0 2], [1 -1 2], 'bo', 'MarkerSize', 10 );
grid on;
r = roots(p);