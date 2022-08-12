% plotting a matrix
x = [ 1 -1 -1 1 1]';
y = [ 1 1 -1 -1 1]';
s = 1:0.21:2;
X = x * s ;
Y = y * s;
figure(1), plot(X,Y,'LineWidth',2);
