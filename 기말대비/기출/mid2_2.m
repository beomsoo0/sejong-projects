clear clc
syms i t
L=3; R=10; C=80*10^-6;
i = dsolve('L*D2i+R*Di+1/C*i=10', 'i(0)=0', 'Di(0)=8');
