%% 구와 실린더 그리기

%% Data Generation
[ X1, Y1, Z1 ] = sphere(20);
t = linspace(0,pi,20);
r = 1 + sin(t);
[ X2, Y2, Z2 ] = cylinder(r);

%% 3차원 그래프
figure('Position', [200 200 800 300], 'color', 'w');
subplot(1,2,1), surf(X1,Y1,Z1), axis square;
subplot(1,2,2), surf(X2,Y2,Z2), axis square;
colormap('jet');
% colormap('parula');
% colormap('colorcube');
% colormap('prism');
% colormap('cool');
% colormap('spring');
% colormap('summer');
% colormap('autumn');
% colormap('winter');