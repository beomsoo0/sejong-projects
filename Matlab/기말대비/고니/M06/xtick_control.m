x  = linspace(0, 4*pi, 1000);
y1 = sin(x); y2 = sin(x).^2;
f1 = figure( 'Position', [100 200 600 200] );
plot( x, y1, 'b-', x, y2, 'r-' ); grid on;
hx = xlabel('$x$'); set(hx, 'Interpreter', 'LaTeX');
xlim([0 4*pi]); ax = gca; ax.XTick = [0:pi:4*pi];
ax.XTickLabel = {'0', '\pi', '2\pi','3\pi','4\pi'};
hl = legend('$\sin (x)$','$\sin^2(x)$', 'Location', 'SouthEast');
hl.Interpreter = 'LaTeX';
annotation(f1,'textarrow',[0.385530227948464 0.34786917740337],...
    [0.490902834008097 0.3582995951417],'String',{'sin(x)'});