%% �� ���� ������ 2���� ������ ���ϱ�
% $P_1 = (-2, -1)$, $P_2 = (1,1)$, $P_3 = (2,0)$�� ������
% 2�� ������ $y=ax^2 + bx + c$�� ��� $a, b, c$�� ���Ͻÿ�.
%

%% �� ���� ��ǥ�� ���׽Ŀ� �����Ͽ� ���� ������ �����
px = [-2 1 2]';
py = [-1 1 0]';
A  = [4 -2 1; 1 1 1; 4 2 1]

%% ��� ���ϱ�
c  = A \ py

%% �׷��� �׸���
x  = -3:0.01:3;
y  = polyval(c,x);
figure(1);
h = plot(x, y, 'b-', px, py, 'ro', 'LineWidth', 2);
grid;
set(h(2),'MarkerSize',10);
xlabel('$x$', 'Interpreter', 'latex');
ylabel('$y$', 'Interpreter', 'latex');