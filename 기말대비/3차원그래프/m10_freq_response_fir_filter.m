%% Frequency response of an FIR filter
% The $z$-transform of an FIR filter is given as
%
% $H(z)=1+2z^{-1}+z^{-2}$
%
% Plot $|H(z)|$ over $z$-plane, where $z=x+jy$ and
% $x = -1.5 \sim 1.5$ and $y = -1.5 \sim 1.5$.
%
% Plot the frequency response of the FIR filter, 
% which is given as the magnitude of $H(z)$ 
% over the unit circle, $z=e^{j\theta}$.
%

%% $z$-transform of the FIR filter
[X, Y] = meshgrid( -1.5:0.1:1.5, -1.5:0.1:1.5);
Z  = X + 1i*Y;
Hz = 1 + 2*Z.^(-1) + Z.^(-2);

%% The magnitude over $z$-plane
figure('Color', 'w');
surf(X,Y,abs(Hz), min(abs(Hz),5)); zlim([0 5]);
view(30,60);
hold on;

%% The frequency response over the unit circle
t  = 0:0.1:2*pi;
x  = cos(t); y = sin(t); z = x + j*y;
hz = 1 + 2*z.^(-1) + z.^(-2);
plot3(x,y,abs(hz),'r-','LineWidth',2);
plot3(1,0,4,'yo', ...
    'MarkerSize',10,'MarkerFaceColor','blue', ...
    'MarkerEdgeColor','blue');
hold off;
xlabel('x'); ylabel('y');
box on;
