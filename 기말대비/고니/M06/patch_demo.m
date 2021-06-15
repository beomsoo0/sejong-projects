xdata = [2     2     0     2     5;
         2     8     2     4     5;
         8     8     2     4     8];
ydata = [4     4     4     2     0;
         8     4     6     2     2;
         4     0     4     0     0];
cdata = [9     0     4     6    10;
         15    2     5     7     9;
         8     3     0     8     3];
% colormapeditor
figure(1);
p = patch(xdata,ydata,cdata, ...
    'Marker','o','MarkerFaceColor','flat', ...
    'FaceColor','none');
set(p,'EdgeColor','interp');