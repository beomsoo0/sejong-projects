%% Equivalent Patch
% Patch is a low level plot command.

X = [0.0 0.5 0.5;
     0.0 1.0 1.0;
     0.5 1.0 0.0;
     1.0 0.5 0.0];
Y = [1.0 0.0 0.0;
     0.5 0.0 0.0;
     0.5 1.0 1.0;
     1.0 0.5 0.5];
Z = [0.0 0.0 0.0;
     0.0 0.0 0.0;
     0.5 1.0 0.0;
     1.0 0.5 0.0];
C = [1 15 1;
     1 15 1;
     1 15 1;
     1 15 1];

figure('Color', 'w');
patch( X, Y, Z, C);
view(3); grid on;
xlabel('x'); ylabel('y'); zlabel('z');
