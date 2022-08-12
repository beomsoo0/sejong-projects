% Color Ball
N  = 100;
r  = [ 0 ones(1,N) ];
I  = ones(N+1,1);
figure(1);
C  = I*[ 55 7 3 49];
T  = 0:0.2:10*pi;
for n = 1:length(T)
    t   = T(n);
    t0  = linspace( 0, pi/2, N ) + t;
    t1  = [ 0 t0 ];
    x1  = r .* cos(t1);        y1  = r .* sin(t1);
    x2  = r .* cos(t1+pi/2);   y2  = r .* sin(t1+pi/2);
    x3  = r .* cos(t1+pi);     y3  = r .* sin(t1+pi);
    x4  = r .* cos(t1+3*pi/2); y4  = r .* sin(t1+3*pi/2);
    X   = [x1' x2' x3' x4' ];
    Y   = [y1' y2' y3' y4' ];
    p = patch(X, Y, C, 'FaceColor', 'flat');
    set(gca,'CLim',[0 64]);
    axis square;
    M(n) = getframe;
end
clf;
axes('Position',[0 0 1 1]);
movie(M,1, 30);
