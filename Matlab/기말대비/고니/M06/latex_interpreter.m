x  = linspace(0, 7*pi, 1000);
y1 = sin(x); y2 = sin(x).^2;
figure( 'Position', [100 200 600 200] );
plot( x, y1, 'b-', x, y2, 'r-' ); grid on;
hx = xlabel('$x$'); set(hx, 'Interpreter', 'LaTeX');
xlim([0 7*pi]);
text(19.0, -0.5, '$\sin (x)$', 'Interpreter', 'LaTeX');
text(16.5,  0.3, '$\sin^2(x)$', 'Interpreter', 'LaTeX');