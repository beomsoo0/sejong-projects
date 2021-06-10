clear
clc
R =4; L=1.3; V=12;
t1 = [0:0.01:0.5];
t2 = [0.5:0.01:2];
i1 = V/R * (1 - exp((-R*t1)/L));
i2 = exp(-(R*t2)/L)*V/R*(exp((0.5*R)/L)-1);
plot(t1, i1, t2, i2)
