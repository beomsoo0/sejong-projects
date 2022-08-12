% Patch 
xdata = [0     0     0     8;
         8     0     8     8;
         4     4     4     4];
ydata = [0     0     8     8;
         0     8     8     0;
         4     4     4     4];
cdata = [4     8    12    15;
         4     8    12    15;
         0     0     0     0];
% colormapeditor
colormap('Cool');
figure(1);
p = patch(xdata,ydata,cdata,'FaceColor','interp');
set(p,'EdgeColor','interp');