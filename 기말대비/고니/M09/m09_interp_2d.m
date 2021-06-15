%% 왼 손 본 뜨기
% 왼 손 주위로 30개의 점을 찍어 얻은 샘플값을 바탕으로 보간법을 적용하여
% 왼손의 모양을 그리시오.
%

%% 왼 손 주위로 점 찍기
N = 30;
figure('Position', [10 10 900 900]);
Sx = 100 * [-1 1 1 -1 -1];
Sy = 100 * [-1 -1 1 1 -1];
plot( Sx, Sy, 'r-', 'LineWidth', 4 );
grid on; hold on;
h = helpdlg('왼손을 네모안에 놓고 그 주위에 점 30개를 클릭 하세요', ...
    'Point Selection');
x = zeros(N,1);
y = zeros(N,1);
for n=1:N
    [x1,  y1] = ginput(1);
    plot( x1, y1, 'bo', 'MarkerSize', 10 );
    x(n) = x1;
    y(n) = y1;
end

k  = 0:N-1;
ki = 0:0.1:N-1;

xi1 = interp1( k, x, ki, 'linear' );
yi1 = interp1( k, y, ki, 'linear' );

xi2 = interp1( k, x, ki, 'pchip' );
yi2 = interp1( k, y, ki, 'pchip' );

xi3 = interp1( k, x, ki, 'spline' );
yi3 = interp1( k, y, ki, 'spline' );

h = plot( xi1, yi1, 'b-', xi2, yi2, 'r-', ...
          xi3, yi3, 'g-', 'LineWidth', 2 );

legend( h, {'linear', 'cubic', 'spline'} );
hold off;
