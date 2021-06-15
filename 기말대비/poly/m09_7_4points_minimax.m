%% 4개의 점을 지나는 3차 다항식 곡선의 최대 최소값
% 4개 점의 좌표: (-4, -1), (-1, 2), (0, -1), (3, 1)

%% Polynomial passing through 4 points
x0 = [ -4.5 3.2 ];
xs = [ -4 -1  0  3];
ys = [ -1  2 -1  1];
n  = length(xs) -1; % 몇차방정식?
p  = polyfit( xs, ys, n );
x  = linspace( x0(1), x0(end), 100 );
y  = polyval( p, x );
figure(1); plot( x, y, 'b-', xs, ys, 'ro', 'MarkerSize', 10 );
xlim( x0 );
grid on; hold on;
xlabel('$x$', 'Interpreter', 'latex' );
ylabel('$y$', 'Interpreter', 'latex' );

%% Minima and maxima
pd = polyder( p );
rd = roots( pd );
xm = [ x(1), x(end), rd' ];
ym = polyval( p, xm );
[mm, mi] = sort( ym );
fprintf('min = %.2f at x=%.1f\n', mm(1), xm(mi(1)) );
fprintf('max = %.2f at x=%.1f\n', mm(end), xm(mi(end)) );
plot( xm, ym, 'ko', 'MarkerFaceColor', 'k' );
hold off;
