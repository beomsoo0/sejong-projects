%% 3점에 가장 가까운 직선의 방정식
% 세 점 $(x_1, y_1)$, $(x_2, y_2)$, $(x_3, y_3)$과 가장 가까운 직선의
% 방정식을 $y=ax + b$라고 할 때 최소 자승법을 이용하여 $a$와 $b$를 구하시오.
%

%% polyfit()을 이용하여 계수 구하기 
px = [-2 1 2];
py = [-1 1 0];
p  = polyfit(px, py, 1);
fprintf('a = %f, b = %f\n', p(1), p(2) );

%% 직선과 세 점을 나타내기
x  = -3:0.01:3;
y  = polyval(p,x);
figure(1);
h = plot(x,y,'b-',px,py,'ro','LineWidth',2);
grid;
set(h(2),'MarkerSize',10);
hold on;
plot([-3 3],[0 0],'r-',[0 0], [-2 2],'r-');
hold off;
xlabel('$x$', 'Interpreter', 'latex');
ylabel('$y$', 'Interpreter', 'latex');
text( -2.5, 1.2, '$y=ax+b$', 'Interpreter', 'latex', 'FontSize', 12 );
text( -2.5, 0.8, sprintf('$a=%f$', p(1)), 'Interpreter', 'latex', ...
    'FontSize', 12 );
text( -2.5, 0.4, sprintf('$b=%f$', p(2)), 'Interpreter', 'latex', ...
    'FontSize', 12 );

