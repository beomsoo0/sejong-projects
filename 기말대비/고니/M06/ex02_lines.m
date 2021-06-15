%
clear; clc;
%%
A = zeros(2,10);
A(1,2:2:10) = 1:2:9;
A(2,2:2:10) = 2:2:10;
a = A(:);
c = a; c(c==0) = 10;

B = repmat(10,2,10);
B(1,1:2:10) = 0:2:8;
B(2,1:2:10) = 1:2:9;
b = B(:);
d = b; d(d==10) = 0;

x = [a; b];
y = [c(end:-1:1); d(end:-1:1)];

figure(1);
plot(x,y,'bo-', 'linewidth', 2 );
xlim([-1 11]); ylim([-1 11] );
grid on; axis square;

