%% 3D graphs from different view point
% $z = 1.8^{-1.5 \sqrt{x^2+y^2}} \sin(x) \cos(y/2)$

%% Data
[ X, Y ] = meshgrid([-3:0.25:3],[-3:0.25:3]);
Z  = 1.8.^(-1.5*sqrt(X.^2+Y.^2)).*sin(X).*cos(Y/2);

%% from 4 different view points
figure('Position', [200 200 800 600], 'color', 'w');
subplot(2,2,1), mesh(X,Y,Z); xlabel('x'), ylabel('y'), zlabel('z');
% view(3);
subplot(2,2,2), mesh(X,Y,Z); xlabel('x'), ylabel('y'), zlabel('z');
view(2); % view( 0, 90 );
subplot(2,2,3), mesh(X,Y,Z); xlabel('x'), ylabel('y'), zlabel('z');
view(90, 0); 
subplot(2,2,4), mesh(X,Y,Z); xlabel('x'), ylabel('y'), zlabel('z');
view( 0, 0);
