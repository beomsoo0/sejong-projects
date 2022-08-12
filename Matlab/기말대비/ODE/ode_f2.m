function ydot = ode_f2(t,y)

% y" - 3*y' + 2*y = 3*cos(t)

% y1' = y2
% y2' = 3*y2 - 2*y1 + 3*cos(t)

ydot = [y(2); 3*y(2) - 2*y(1) + 3*cos(t)];
