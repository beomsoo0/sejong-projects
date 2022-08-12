figure(1);
r  = 1;
th = (pi/6:0.01:11*pi/6)';
s  = r * exp(1i*th);
patch( [0; real(s); 0], [0; imag(s); 0], 'g' );
axis equal
axis square
