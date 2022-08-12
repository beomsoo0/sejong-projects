%% Snake Lines
% x-coordinates
A  = reshape(1:10, 2,[]); Z  = zeros(size(A));
X1 = [Z; A];              x1 = reshape(X1, [],1 );
T  = 10 + zeros( size(A));
X2 = [A-1;T];             x2 = reshape(X2, [], 1);
x  = [x1; x2];

% y- coordinates
B  = reshape(10:-1:1, 2, []);
Y1 = [B;T];              y1 = reshape(Y1, [], 1);
Y2 = [ Z; B-1];          y2 = reshape(Y2, [], 1);
y  = [y1; y2];

figure(1);
plot( x, y, 'bo-', 'MarkerFaceColor', 'r', 'LineWidth', 2 );
axis([-1 11 -1 11]); axis square; grid on;


