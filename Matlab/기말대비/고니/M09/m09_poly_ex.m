%% 다항식의 계수를 구하고 그래프 그리기
% $f(x) = (x+1.2)(x+0.6)(x-0.1)(x-1.9)$
%
% 다항식 $f(x)$의 계수를 구하고 $x=-1.5 \sim 2$ 구간에 대하여 
% 그래프를 구하시오.
%

r  = [-1.2 -0.6 0.1 1.9];
p  = poly( r );
y0 = polyval( p, r ); % y0 = zeros(size(r));
x  = linspace(-1.5, 2, 1000);
y  = polyval( p, x );

figure(1);
plot( x, y, 'b-', r, y0, 'ro' );
grid on;
xlabel('$x$', 'Interpreter', 'latex');
ylabel('$f(x)$', 'Interpreter', 'latex');
text( -0.9, 1.5, '$f(x) = (x+1.2)(x+0.6)(x-0.1)(x-1.9)$', ...
    'Interpreter', 'latex' );

