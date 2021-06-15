%% 세 점을 지나는 2차원 방정식 구하기
% $P_1 = (-2, -1)$, $P_2 = (1,1)$, $P_3 = (2,0)$을 지나는
% 2차 방정식 $y=ax^2 + bx + c$의 계수 $a, b, c$를 구하시오.
%

%% 세 점의 좌표를 다항식에 대입하여 연립 방정식 만들기
px = [-2 1 2]';
py = [-1 1 0]';
A  = [4 -2 1; 1 1 1; 4 2 1]

%% 계수 구하기
c  = A \ py

%% 그래프 그리기
x  = -3:0.01:3;
y  = polyval(c,x);
figure(1);
h = plot(x, y, 'b-', px, py, 'ro', 'LineWidth', 2);
grid;
set(h(2),'MarkerSize',10);
xlabel('$x$', 'Interpreter', 'latex');
ylabel('$y$', 'Interpreter', 'latex');