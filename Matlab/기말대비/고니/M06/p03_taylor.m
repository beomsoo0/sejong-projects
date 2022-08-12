k  = (1:2:13)';
nK = length(k);
s  = (-1).^(0:nK-1);
t  = -10:0.01:10;
nT = length(t);
X  = zeros(nK+1, nT);
x  = s(1) * t .^ k(1) / factorial(k(1));
X(1,:) = x;
for ki=2:nK
    x       = s(ki) * t .^ k(ki) / factorial(k(ki));
    X(ki,:) = X(ki-1,:) + x;
end
X(nK+1,:) = sin(t);
%%
f = figure(1);
h = plot( t, X' ); set( h(nK+1), 'LineWidth', 2 );
ylim([-10 10] ); grid on;
xlabel( '$t$', 'Interpreter', 'latex' );
title('Taylor Series Approximation of $\sin(t)$', 'Interpreter', 'latex');
annotation(f, 'textarrow',[0.8 0.77], [0.47 0.52], ...
    'TextEdgeColor','none', 'String',{'$\sin(t)$'}, 'Interpreter', 'latex');
annotation(f,'textarrow',[0.59 0.63], [0.69 0.63], ...
    'TextEdgeColor','none', 'String',{'$T(t,1)=t$'}, 'Interpreter', 'latex');

