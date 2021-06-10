%% ���׽��� ���� ���ϰ� �׷����� ��Ÿ����
% $f(x) = x^5 - 5 x^3 + 4x$
%
% Step 1: $x=-2.1 \sim 2.1$�� ������ ���Ͽ� �׷����� �׸��ÿ�.
%
% Step 2: ���׽� $f(x)$�� �Ǳ��� ���ϰ� �׷����� ��Ÿ���ÿ�.
%

%% �׷��� �׸���
p = [1  0  -5  0  4  0];  % f(x)�� ���
x = linspace( -2.1, 2.1, 1000 );
y = polyval( p, x );
figure(1);
plot( x, y, 'LineWidth', 2);
hold on; plot([-2.5 2.5],  [0 0], 'k-');
grid on;

%% �Ǳ� ���ϰ� ��Ÿ����
r  = roots(p); 
y0 = zeros(size(r));
plot( r,y0,'ro', 'MarkerSize', 10, 'LineWidth', 2);
text( -0.5, 2, '$f(x) = x^5 - 5 x^3 + 4x$', ...
    'Interpreter', 'latex', 'FontSize', 16);
