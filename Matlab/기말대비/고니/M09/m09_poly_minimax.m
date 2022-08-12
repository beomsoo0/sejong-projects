%% ���׽��� �ִ� �ּ� ���ϱ�
% $f(x) = (x+1.2)(x+0.6)(x-0.1)(x-1.9)$
%
% $x=-1.5 \sim 2$�� ������ ���Ͽ� $f(x)$�� �׷����� �׸���
% ������ �ִ밪(local maximum) �� �ּҰ�(local minimum)�� 
% �Բ� ��Ÿ���ÿ�.
%

%% Step 1: ���׽��� ���Լ� ���ϱ�
r  = [-1.2 -0.6 0.1 1.9];
p  = poly( r );
pd = polyder( p )

%% Step 2: ���Լ��� �� ���ϱ�
rd = roots( pd )

%% Step 3: �ذ� ���ϱ�
yd = polyval( p, rd )

%% Step 4: �׷��� �׸���
x  = linspace(-1.5, 2, 1000);
y  = polyval( p, x );
figure(1);
plot( x, y, 'b-', rd, yd, 'ro' );
grid on;
xlabel('$x$', 'Interpreter', 'latex');
ylabel('$f(x)$', 'Interpreter', 'latex');
text( -0.9, 1.5, '$f(x) = (x+1.2)(x+0.6)(x-0.1)(x-1.9)$', ...
    'Interpreter', 'latex' );

