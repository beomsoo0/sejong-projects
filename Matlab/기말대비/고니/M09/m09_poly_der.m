%% 다항식의 미분
% $p_1 (x) = x^5 - 5 x^3 + 4x$
%
% $p_2 (x) = x^2 + 2 x$
%

%% 다항식 $p_1 (x)$의 미분
p1  = [1  0  -5  0  4  0];
p1d = polyder(p1)

%% 다항식 $p_1 (x) \times p_2 (x)$의 미분
p2 = [1  2  0];
pd = polyder(p1, p2)

%% 다항식 $p_1 (x) / p_2 (x)$의 미분
[n d ] = polyder(p1, p2)

%% 지역적 최대 최소 값을 갖는 x 값
p1  = [1  0  -5  0  4  0];
p1d = polyder(p1);
x   = -2.5:0.01:2.5;
y   = polyval(p1, x);
figure(1); plot(x, y); grid on; ylim([-5 5]);
mx  = roots(p1d);
my  = polyval( p1, mx );
hold on; plot( mx, my, 'ro');