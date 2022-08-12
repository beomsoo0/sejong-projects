s0 = xlsread('kospi.xlsx','B1:B20');
s1 = s0(end:-1:1);
figure, bar(s1), axis([1 length(s1) 1600 1800]);