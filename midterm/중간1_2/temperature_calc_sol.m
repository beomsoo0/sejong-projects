clear, clc;
C=13.83; Eg=0.67; k=8.62*10^(-5);
T=xlsread('temperature.xlsx');
sigma = exp(C-Eg/(2*k*T));
tbl = [T sigma];
xlswrite('conductivity.xlsx', tbl);