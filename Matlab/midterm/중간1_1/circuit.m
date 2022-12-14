t1 = [0:0.01:0.5];
t2 = [0.5:0.01:2];
R = 4;
L = 1.3;
V = 12;
i1 = (1 - exp(-t1 * R/L)) * V/R;
i2 = exp(-t2 * R/L).*(exp(0.5*R/L) - 1) * V / R;
plot(t1, i1, t2, i2);