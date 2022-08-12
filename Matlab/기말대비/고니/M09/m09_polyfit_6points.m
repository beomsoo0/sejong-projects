%% 최소자승법을 이용한 데이터 피팅에서 고차 다항식의 영향
% 1차 방정식에 의해 표현되는 현상을 관찰할 때 센서의 잡음이 상당한 경우
% 필요 이상의 고차 다항식을 이용하여 데이터 피팅을 하는 경우 실험 데이터는
% 근사하게 나타내지만 실제 물리 법칙과 다를 수 있습니다.
%

%% 모의 실험 데이터
x = [1 3 4 6 8 10];
y = 2.5*x + 2 + 3*randn(size(x));

figure(1);
plot(x,y,'ro','LineWidth',2,'MarkerSize',10);
grid; hold on; axis([0 11 -5 30]);

%% 고차 방정식을 이용한 데이터 피팅 결과
x1 = 0:0.01:11;
linespec = ['b-','r-','k-'];
for n=1:2:5
    p = polyfit(x,y,n);
    y1 = polyval(p,x1);
    plot(x1,y1,linespec(n), 'LineWidth', 2);
end
hold off;
legend('Experiment','1st order poly', '3rd order poly',...
    '5th order poly', 'Location', 'SouthEast');
xlabel('$x$', 'Interpreter', 'latex');
ylabel('$y$', 'Interpreter', 'latex');
