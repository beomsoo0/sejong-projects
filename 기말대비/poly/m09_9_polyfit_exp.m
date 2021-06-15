%% 지수 함수 데이터 피팅
% 어떤 실험 데이터가 $y=b e^{mx}$의 법칙을 따른다고 가정할 때, 
% 측정된 실험 데이터와 가장 잘 맞는 계수 $b$와 $m$을 구하시오.
%

%% 측정된 실험 데이터
x = 0:0.5:5;
y = [3.50 2.69 2.02 1.74 1.17 1.05 0.89 0.63 0.50 0.35 0.15];
figure(1);
plot(x,y,'ro','LineWidth',2,'MarkerSize',10);
grid; hold on; axis([0 5 0 3.6]);

%%  $y=b e^{mx}$ 함수의 계수 찾기
Y = log(y);
p = polyfit( x, Y, 1 );
m = p(1);
b = exp(p(2));
fprintf('b = %f\n', b );
fprintf('m = %f\n', m );
x1 = linspace(0, 5, 1000);
y1 = b * exp( m*x1 );
plot( x1, y1, 'b-' );
xlabel('$x$', 'Interpreter', 'latex');
ylabel('$y$', 'Interpreter', 'latex');
text( 2, 2.8, '$y =b e^{mx}$', 'Interpreter', 'latex', 'FontSize', 12 );
text( 2, 2.6, sprintf('$b=%f$', b), 'Interpreter', 'latex', ...
    'FontSize', 12 );
text( 2, 2.4, sprintf('$m=%f$', m), 'Interpreter', 'latex', ...
    'FontSize', 12 );
grid on; hold off;

