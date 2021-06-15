xs = [-4:0.05:4];
ys = [-4:0.05:6];
[Xs, Ys] = meshgrid(xs,ys);
Fs = Xs.^2-Ys;
figure(1);
contour(xs,ys,Fs,[-1 0 1 2 3 4 5])
hold on

dx=0.5; dy=0.5;
x=[-3:dx:3]; y=[-2.5:dy:4];
[X,Y]=meshgrid(x,y);
F = X.^2-Y;
[dFx,dFy] = gradient(F,dx,dy);
quiver(x,y,dFx,dFy)