xdata = [2     2     ;
         2     8     ;
         8     8     ];
ydata = [4     4     ;
         8     4     ;
         4     0     ];
cdata = [9     0     ;
         15    2     ;
         8     3     ];
% colormapeditor
figure(1);
p = patch(xdata,ydata,cdata,  'Marker','o','FaceColor','interp');
p.EdgeColor = 'interp';
