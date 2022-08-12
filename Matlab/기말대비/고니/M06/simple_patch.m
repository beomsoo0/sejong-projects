%% Simple Square patch
X = [0 1 1 0]';
Y = [0 0 1 1]';
figure(1); p = patch( X, Y, 'b' );
axis([-2 2 -2 2]); axis equal;
grid on;
p %#ok<*NOPTS>

%%
X = [0 1 1 0; 0.5 2 2 0.5 ]';
Y = [0 0 1 1; 0.5 0.5 2 2 ]';
C = [0 0 1 1; 0 1 1 0]';
figure(1); p = patch( X, Y, 'b' );
% figure(1); p = patch( X, Y, C );

axis([-1 2 -1 2]);
% p.FaceColor = 'none';
% p.LineWidth = 3;
ax = gca;
% ax.Color = 'r';
grid on;

