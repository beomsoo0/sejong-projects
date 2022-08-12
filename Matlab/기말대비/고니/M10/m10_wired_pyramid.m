%% 피라미드 한 붓 그리기

x = [ -1 -1  1  1 -1  1  0  1 -1  0 -1 ];
y = [  1 -1 -1  1  1 -1  0  1 -1  0  1 ];
z = [  0  0  0  0  0  0  1  0  0  1  0 ];
figure(1);
plot3(x, y, z, 'b-', 'LineWidth', 2);
grid on; xlabel('x'); ylabel('y');
