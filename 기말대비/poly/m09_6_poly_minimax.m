%% 다항식의 최대 최소 구하기
% $f(x) = (x+1.2)(x+0.6)(x-0.1)(x-1.9)$
%
% $x=-1.5 \sim 2$의 범위에 대하여 $f(x)$의 그래프를 그리고
% 지역적 최대값(local maximum) 및 최소값(local minimum)을 
% 함께 나타내시오.
%

%% Step 1: 다항식의 도함수 구하기
r  = [-1.2 -0.6 0.1 1.9];
p  = poly( r );
pd = polyder( p )

%% Step 2: 도함수의 근 구하기
rd = roots( pd )

%% Step 3: 극값 구하기
yd = polyval( p, rd )

%% Step 4: 그래프 그리기
x  = linspace(-1.5, 2, 1000);
y  = polyval( p, x );
figure(1);
plot( x, y, 'b-', rd, yd, 'ro' );
grid on;
xlabel('$x$', 'Interpreter', 'latex');
ylabel('$f(x)$', 'Interpreter', 'latex');
text( -0.9, 1.5, '$f(x) = (x+1.2)(x+0.6)(x-0.1)(x-1.9)$', ...
    'Interpreter', 'latex' );

