% Color Ball
t0 = 0:0.01:pi/2;
t  = [ 0 t0 ];
N  = length(t);
r  = [ 0 ones(1,N-1) ];
x  = r .* cos(t);
y  = r .* sin(t);
X  = [x' -x' -x' x' ];
Y  = [y'  y' -y' -y'];
I  = ones(N,1);
C  = [2.8711*I 8.4961*I 11.3086*I 6.9140*I];
colormap('jet');
figure(1), p = patch(X, Y, C, 'FaceColor', 'flat');
axis square;