%% 3D graphs from different view point
% $z = 1.8^{-1.5 \sqrt{x^2+y^2}} \sin(x) \cos(y/2)$

%% Data
[ X, Y ] = meshgrid( -8 : .5 : 8 ); 
R = sqrt(X.^2 + Y.^2) + eps;
Z = sin(R) ./ R;

%% Different colorings
figure('Position', [200 200 800 600], 'color', 'w');
subplot(2,2,1), mesh( X, Y, Z, 'EdgeColor', 'b');
subplot(2,2,2), surf(X,Y,Z); colormap('hsv'); 
subplot(2,2,3), surf(X,Y,Z); alpha(0.4);
subplot(2,2,4), surf(X,Y,Z,'FaceColor','red','EdgeColor','none');
camlight left; lighting phong;