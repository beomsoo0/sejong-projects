% Color Ball
t0 = 0:0.01:pi/4;
t  = [ 0 t0 ];
N  = length(t);
r  = [ 0 ones(1,N-1) ];
x  = r .* cos(t);
y  = r .* sin(t);
u  = r .* cos(t+pi/4);
v  = r .* sin(t+pi/4);
X  = [x' u' -u' -x' -x' -u'  u'  x' ];
Y  = [y' v'  v'  y' -y' -v' -v' -y' ];
I  = ones(N,1);

figure(1);
colormap('colorcube');
set(gca,'CLim',[0 64]); 
C  = I*[ 12 8 38 43 12 8 38 43];
colormap('colorcube');
p = patch(X, Y, C, 'FaceColor', 'flat');
axis square;