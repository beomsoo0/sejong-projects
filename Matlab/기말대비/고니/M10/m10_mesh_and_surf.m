%% Mesh�� Surf�� �̿��� 3���� �׷���

%% 3���� ��ǥ �����
x = -1:3;
y =  1:4;
[ X, Y ] = meshgrid(x,y);
Z = X .* Y.^2 ./ (X.^2 + Y.^2);

%% 3���� �׷��� �׸���
figure(1);
mesh(X,Y,Z);
xlabel('x'); ylabel('y'); zlabel('z');
set( gcf, 'color', 'w' );

figure(2);
surf(X,Y,Z);
xlabel('x'); ylabel('y'); zlabel('z');
set( gcf, 'color', 'w' );