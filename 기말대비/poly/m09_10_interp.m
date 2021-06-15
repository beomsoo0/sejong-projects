%% 다양한 인터폴레이션 기법
% 샘플값으로부터 그 사이 값을 찾아내는 방법

%% 샘플 데이터
x = [0.1 0.2 0.4 0.5 0.9 1.0];
y = x .* sin(pi*x);
figure(1);
plot(x,y,'ro','LineWidth',2,'MarkerSize',10);
grid; hold on;
xlabel('x'); ylabel('y');

%% 인터폴레이션
xi   = 0:0.01:1;
yi_n = interp1(x,y,xi,'nearest');
yi_l = interp1(x,y,xi,'linear');
yi_s = interp1(x,y,xi,'spline');
yi_c = interp1(x,y,xi,'pchip');
plot(xi,yi_n,xi,yi_l,xi,yi_s,xi,yi_c,'LineWidth',2);
legend('Exp','Nearest','Linear','Spline','Cubic', ...
       'Location','NorthWest');
