[X, Y] = meshgrid(-2:0.2:2);
Dx  = sin(Y);
Dy  = sin(X);
figure(1), quiver(X, Y, Dx, Dy );
R = 1.5;
axis([-1 1 -1 1]*R);
xlabel('$x$', 'Interpreter', 'latex');
ylabel('$y$', 'Interpreter', 'latex');
%%


