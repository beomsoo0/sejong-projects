
t = linspace(0, 2*pi, 100)';
x = cos(t); y = sin(t);
z = ones(size(x));
% r = (1:-0.1:0);
% h = 2*(0:0.1:1);
r = (1:-0.01:0);
h = 2*(0:0.01:1);
X = x * r;
Y = y * r;
Z = z * h;
%% 3차원 그래프
figure(1);
surf( X, Y, Z, 'LineStyle', 'none');
grid on;
xlabel('x'); ylabel('y'); zlabel('z');