% Fibonacci plot
clear; clc; close all;
%% Parameters
N = 8; % Fibonacci order
W = round(Fibo(N) + Fibo(N-3));
%%
figure(1);
r  = 1;
th = 0:0.01:pi/2;
s  = r * exp(1i*th);
plot( real(s), imag(s), 'LineWidth', 2 );
axis([-W W -W W]); axis square;
hold on; grid on;
f  = zeros(N,1); % radius of the arcs, real
c  = zeros(N,1); % center of the arcs, complex
f(1) = 0; f(2) = 1;
c(1) = 0; c(2) = 0;
a    = 1i; % current direction
b    = [c(2); c(2)+a*f(2); c(2)+(1+1i)*a*f(2); c(2)+1i*a*f(2); c(2)];
plot( real(b), imag(b), 'r-' );
for k=3:(N+1)
    f(k) = f(k-1) + f(k-2);     % radius
    c(k) = c(k-1) - a * f(k-2); % center
    s    = a * f(k) * exp(1i*th) + c(k);
    b    = [c(k); c(k)+a*f(k); c(k)+(1+1i)*a*f(k); c(k)+1i*a*f(k); c(k)];
    plot( real(b), imag(b), 'r-' );
    plot( real(s), imag(s), 'LineWidth', 2 );
    a    = a * 1i;
end
hold off;
