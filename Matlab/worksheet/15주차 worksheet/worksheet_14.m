clear all
close all
clc


load('axis_data','x_range','y_range');
load('rod_position','lode1','lode2');

%plot electric rod 
fill(lode1,lode2,'c')
axis([x_range(1) x_range(end) y_range(1) y_range(end)])

%%% (To do) Begin

load('voltage_data', 'voltage_dist');
dx=0.5; dy=0.5;
x=[x_range(1):dx:x_range(end)];
y=[y_range(1):dy:y_range(end)];
[dFx,dFy] = gradient(voltage_dist, dx, dy);
quiver(x,y,dFx,dFy)
hold on

%%% (To do) END

%%%
title ('equipotential contours','fontsize', 18)
xlabel('x','fontsize', 18)
ylabel('y','fontsize', 18) 
set(gca,'fontsize', 18)
axis([x_range(1) x_range(end) y_range(1) y_range(end)])

axis square
set (gca,'xticklabel', [])
set (gca,'yticklabel', [])
%whitebg('black')

