x = randn(1,1000);
[s xbin] = hist(x);
figure, hist(x, xbin);