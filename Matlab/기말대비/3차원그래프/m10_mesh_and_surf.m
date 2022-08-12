%% Mesh와 Surf를 이용한 3차원 그래프

%% 3차원 좌표 만들기
x = -1:3;
y =  1:4;
[ X, Y ] = meshgrid(x,y);
Z = X .* Y.^2 ./ (X.^2 + Y.^2);

%% 3차원 그래프 그리기
figure(1);
mesh(X,Y,Z);
xlabel('x'); ylabel('y'); zlabel('z');
set( gcf, 'color', 'w' );

figure(2);
surf(X,Y,Z);
xlabel('x'); ylabel('y'); zlabel('z');
set( gcf, 'color', 'w' );