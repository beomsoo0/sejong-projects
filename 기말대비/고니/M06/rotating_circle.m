%% 
% Three Circles

N = 100;
t = linspace(0,2*pi, N);
x = cos(t); y = sin(t);

%% 
% Center Intersection

N2 = 100; 
t0 = atan2( sqrt(7), 3 );
t1 = linspace(-t0, t0, N2 );
t2 = linspace( t0, pi - t0, N2 );
x1 = cos(t1); y1 = sin(t1);
x2 = cos(t2); y2 = sin(t2);
xc = [1.5-x1, x2, -1.5+x1, -x2];
yc = [y1, y2, -y1, -y2];
cc = (0:length(xc)-1)/15;

%% 
% Rotating Intersection

figure(3);
plot( 1.1*x, 1.1*y ); hold on;
h = patch( xc, yc, cc );
axis([-1 1 -1 1]*1.2); axis equal; grid on;
colormap('spring');
ts = linspace(0, 2.5*pi, 100);
for t = ts
    c = cos(t); s = sin(t);
    R = [c -s; s c ];
    P = R * [xc; yc];
    h.XData = P(1,:);
    h.YData = P(2,:);
    refresh;
    pause(0.05);
end