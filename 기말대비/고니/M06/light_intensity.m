% Sample Plot for Showing Various Graph Elements
d  = 10:0.1:22;
dd = 10:2:22;
y  = 1000*exp(-0.15*(d-10));
yy = 1000*exp(-0.16*(dd-10));
h  = plot(d,y,'b-',dd,yy,'r-.o');
axis([8 24 0 1200]);
set(h(1),'LineWidth',2);
set(h(2),'LineWidth',2);
xlabel('Distance (cm)');
ylabel('Intensity (lux)');
title('Light Intensity as a Function of Distance');
legend('Theory','Experiment');
grid;

