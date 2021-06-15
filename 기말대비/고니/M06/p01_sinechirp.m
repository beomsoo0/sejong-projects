t = -5:0.0001:5;
y = cos(2*pi*3*t) .* exp( -pi*t.^2 );
figure(1); plot( t-3, y );
xlabel('time $t$', 'Interpreter', 'latex');
ylabel('$s(t)$', 'Interpreter', 'latex');
axis([-2 2 -1 1]);
%%
d = -3:0.05:3;
szD = length(d);
for di = 1:szD
    plot(t+d(di), y );
    xlabel('time $t$', 'Interpreter', 'latex');
    ylabel('$s(t)$', 'Interpreter', 'latex');
    axis([-2 2 -1 1]);
    M(di) = getframe(gcf);
end
% movie(M);
movie2avi(M, 'waves1.avi', 'compression', 'None' );
