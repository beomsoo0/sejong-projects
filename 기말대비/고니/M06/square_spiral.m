%% Square Spiral
x0 = 1:20; 
x1 = x0 .* (-1).^(x0+1);
x2 = reshape(repmat(x1,2,1), 1,[]);
x  = [ 0 x2 ];
y0 = 2:2:20; 
y1 = reshape(repmat(y0,2,1), 1, []);
n1 = 1:length(y1);
y2 = y1 .* (-1).^(n1+1);
y3 = reshape(repmat(y2,2,1), 1, []);
y  = [0 0 y3(1:end-1)];
figure(1);
plot(x,y,'b-o', 'MarkerFaceColor', 'blue');