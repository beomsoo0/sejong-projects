%% 원뿔 그리기
% 높이가 0~2로 바뀜에 따라 반지름이 1에서 0으로 줄어드는 원뿔을 그리시오.

%% 3차원 공간에서 원의 좌표
t = linspace(0, 2*pi, 100)';
x = cos(t);
y = sin(t);
z = ones(size(x));
r = (1:-0.01:0);
h = 2*(0:0.01:1);
X = x * r;
Y = y * r;
Z = z * h;

%% 원뿔의 그래프
figure(1);
surf( X, Y, Z, 'LineStyle', 'none');
grid on;
xlabel('x'); ylabel('y'); zlabel('z');
