%% 다양한 3차원 그래프

%% Data
x = -3:0.25:3;
[ X, Y ] = meshgrid( x, x );
Z = 1.8.^(-1.5*sqrt(X.^2 + Y.^2)).*sin(X).*cos(Y/2);

%% mesh and surf
figure('Position', [200 200 800 300], 'color', 'w');
subplot(1,2,1), mesh( X, Y, Z );
subplot(1,2,2), surf( X, Y, Z );

%% meshz and meshc
figure('Position', [200 200 800 300], 'color', 'w');
subplot(1,2,1), meshz( X, Y, Z );
subplot(1,2,2), meshc( X, Y, Z );

%% surfc and surfl
figure('Position', [200 200 800 300], 'color', 'w');
subplot(1,2,1), surfc( X, Y, Z );
subplot(1,2,2), surfl( X, Y, Z );

%% waterfall and trisurf
figure('Position', [200 200 800 300], 'color', 'w');
subplot(1,2,1), waterfall( X, Y, Z );
subplot(1,2,2), trisurf(delaunay(X,Y),X,Y,Z);

%% contour and contour3
figure('Position', [200 200 800 300], 'color', 'w');
subplot(1,2,1), contour(X,Y,Z,15);
subplot(1,2,2), contour3(X,Y,Z,15);