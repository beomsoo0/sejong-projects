% Rotating Square
x = [1 1 -1 -1 1];
y = [-1 1 1 -1 -1];
figure(1);
for t = 0:0.1:10*pi
    c = cos(t); s = sin(t);
    R = [c -s; s c ];
    P = R * [x; y];
    plot( P(1,:), P(2,:), 'LineWidth', 2 );
    axis([-2 2 -2 2]); axis square;
    grid on;
    pause(0.01);
end
