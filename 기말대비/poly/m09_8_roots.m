%% 다항식의 근을 구하고 그래프로 나타내기
% $f(x) = x^5 - 5 x^3 + 4x$
%
% Step 1: $x=-2.1 \sim 2.1$의 범위에 대하여 그래프를 그리시오.
%
% Step 2: 다항식 $f(x)$의 실근을 구하고 그래프에 나타내시오.
%

%% 그래프 그리기
p = [1  0  -5  0  4  0];  % f(x)의 계수
x = linspace( -2.1, 2.1, 1000 );
y = polyval( p, x );
figure(1);
plot( x, y, 'LineWidth', 2);
hold on; plot([-2.5 2.5],  [0 0], 'k-');
grid on;

%% 실근 구하고 나타내기
r  = roots(p); 
y0 = zeros(size(r));
plot( r,y0,'ro', 'MarkerSize', 10, 'LineWidth', 2);
text( -0.5, 2, '$f(x) = x^5 - 5 x^3 + 4x$', ...
    'Interpreter', 'latex', 'FontSize', 16);
