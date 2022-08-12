%% ���׽��� �̺�
% $p_1 (x) = x^5 - 5 x^3 + 4x$
%
% $p_2 (x) = x^2 + 2 x$
%

%% ���׽� $p_1 (x)$�� �̺�
p1  = [1  0  -5  0  4  0];
p1d = polyder(p1)

%% ���׽� $p_1 (x) \times p_2 (x)$�� �̺�
p2 = [1  2  0];
pd = polyder(p1, p2)

%% ���׽� $p_1 (x) / p_2 (x)$�� �̺�
[n d ] = polyder(p1, p2)

%% ������ �ִ� �ּ� ���� ���� x ��
p1  = [1  0  -5  0  4  0];
p1d = polyder(p1);
x   = -2.5:0.01:2.5;
y   = polyval(p1, x);
figure(1); plot(x, y); grid on; ylim([-5 5]);
mx  = roots(p1d);
my  = polyval( p1, mx );
hold on; plot( mx, my, 'ro');