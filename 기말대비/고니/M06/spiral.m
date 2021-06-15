figure(1);
th1 = 0:0.01:20*pi;
th2 = 0:0.01:30*pi;
subplot(1,2,1); h1 = polar(th1,th1,'r-'); h1.LineWidth = 2;
subplot(1,2,2); h2 = polar(th2,th2,'r-'); h2.LineWidth = 2;