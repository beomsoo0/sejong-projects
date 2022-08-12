%% Using Camera Toolbar

[X,Y] = meshgrid(-8:.5:8); 
R = sqrt(X.^2 + Y.^2) + eps;
Z = sin(R)./R;

figure(1);
surf(X,Y,Z,'FaceColor','red','EdgeColor','none')
camlight left; lighting phong;