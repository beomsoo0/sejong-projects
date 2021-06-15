%% fplot and ezplot
figure(1), fplot('exp(-t^2)*cos(pi*t)', [-4 4], 'k-'); grid;
figure(2), ezplot('cos(1./x)', [-1 1]);
%% Using the basic numeric plot
x = [-1:0.001:1]; y = cos(1./x);
figure(3), plot(x,y);
%% Using a simple anonymous function 
f = @(x) cos(1./x);
figure(4), fplot(f,[-2 2]);
%% Using a funciton m-file
figure(5), fplot(@(x)abs_sin(x), [-5 5]);