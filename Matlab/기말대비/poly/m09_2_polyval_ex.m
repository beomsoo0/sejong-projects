%% 계수로 그래프 그리기
% $f(x) = 5 x^5 + 6 x^2 + 4 x + 2$
%
% Use polyval() to find the value of $f(x)$ at $x=0$ and $x=1$.
%
% Plot the graph of $f(x)$ over $x=-1 \sim +2$.

p  = [5 0 0 6 4 2];
x0 = 0;
y0 = polyval( p, x0 );

x1 = [0 1];
y1 = polyval( p, x1 );

x  = linspace(-1, 2, 1000);
y  = polyval( p, x );

figure(1);
plot( x, y, 'b-', x1, y1, 'ro' );
grid on;
text(0.2, 60, '$f(x) = 5 x^5 + 6 x^2 + 4 x + 2$', ...
    'Interpreter', 'latex' );