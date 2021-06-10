h = [0 600 1500 2300 3000 6100 7900];
T = [100 98.8 95.1 92.2 90 81.2 75.6];
p = polyfit(h, T, 1);
T5000 = polyval(p, 5000);
xpoint = linspace(0, 7900, 100);
ypoint = polyval(p, xpoint);
plot(h, T, 'o', xpoint, ypoint, 'r')