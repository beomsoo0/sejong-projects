% Spiral plot
th = 0:0.01:2*pi;
r  = sin(3*th);
h = polar(th,r,'r-');
set(h, 'LineWidth',2);