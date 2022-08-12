%% Patch Surface of a Man stading with a leg across

%% Load data
load  man_head X Y Z;

%% Patch Plot
figure('Color', 'w');
patch(X, Y, Z, [1 0.75 0.65], 'EdgeColor', 'none', 'FaceAlpha', 1.0);
axis 'equal';    axis 'tight';
xlabel('x, m'); ylabel('y, m'); view(-9, 19); grid on;
light('Position',[1 3 2]);
light('Position',[-3 -1 3]);
% material shiny; 
% material metal;
material dull;
