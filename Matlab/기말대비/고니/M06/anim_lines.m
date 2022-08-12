figure(1);
h = animatedline;
m = animatedline('Marker', 'o');
axis([0,4*pi,-1,1])
set( gca, 'XTick', (0:4)*pi );
set( gca, 'XTickLabel', {'0', '\pi', '2\pi', '3\pi', '4\pi'} );

x = linspace(0,4*pi,100);
y = sin(x);
for k = 1:length(x)
    addpoints(h,x(k),y(k));
    clearpoints(m);
    addpoints(m,x(k),y(k));
    drawnow
end
for k = 1:length(x)
    addpoints(h,4*pi-x(k),y(k));
    clearpoints(m);
    addpoints(m,4*pi-x(k),y(k));
    drawnow
end