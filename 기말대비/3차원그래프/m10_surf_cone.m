%% ���� �׸���
% ���̰� 0~2�� �ٲ� ���� �������� 1���� 0���� �پ��� ������ �׸��ÿ�.

%% 3���� �������� ���� ��ǥ
t = linspace(0, 2*pi, 100)';
x = cos(t);
y = sin(t);
z = ones(size(x));
r = (1:-0.01:0);
h = 2*(0:0.01:1);
X = x * r;
Y = y * r;
Z = z * h;

%% ������ �׷���
figure(1);
surf( X, Y, Z, 'LineStyle', 'none');
grid on;
xlabel('x'); ylabel('y'); zlabel('z');
