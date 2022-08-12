% Polar, Plot and Patch demo
%% a wing
t1 = 0:0.01:pi/3; % counter-clockwise
tr = t1(end:-1:1); % reverse direction
nt = length(t1);
th = [t1 tr 0];
r1 = [ones(1,nt) 0.3*ones(1,nt) 1];
%% a circle
t2 = 0:0.01:2*pi;
r2 = ones(1,length(t2));
%% Polar
figure(1);
h1  = polar( th, r1, 'r-'); hold on;
h2  = polar( th+2/3*pi, r1, 'r-');
h3  = polar( th-2/3*pi, r1, 'r-');
h0  = polar( t2, 0.25*r2, 'r-');
set([h0 h1 h2 h3], 'LineWidth', 3);
hold off;
%% Plot
figure(2);
h1  = plot( r1.*cos(th), r1.*sin(th), 'r-'); hold on;
h2  = plot( r1.*cos(th+2/3*pi), r1.*sin(th+2/3*pi), 'r-');
h3  = plot( r1.*cos(th-2/3*pi), r1.*sin(th-2/3*pi), 'r-');
h0  = plot( 0.25*r2.*cos(t2), 0.25*r2.*sin(t2), 'r-');
set([h0 h1 h2 h3], 'LineWidth', 3);
axis square;
hold off;
%% Patch - filled polygons
figure(3);
h1  = patch( r1.*cos(th), r1.*sin(th), 'k'); hold on;
h2  = patch( r1.*cos(th+2/3*pi), r1.*sin(th+2/3*pi), 'k');
h3  = patch( r1.*cos(th-2/3*pi), r1.*sin(th-2/3*pi), 'k');
h0  = patch( 0.25*r2.*cos(t2), 0.25*r2.*sin(t2), 'k');
set(gca,'Color','blue');
axis square;
hold off;

