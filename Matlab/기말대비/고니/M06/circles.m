% Joining Circles
t = 0:0.1:2*pi+0.1; % angles
N = length(t);
x = cos(t');
y = sin(t');

%%
c = -5.5:5.5; % center of the circles
C = repmat(c,N,1);
r = abs(c);     % radius of the circles

X = x*r + C;
Y = y*r;
plot(X,Y) % plot the circles
