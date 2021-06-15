close all; clear; clc;
%% Data set
d  = 10:0.1:22;
dd = 10:2:22;
y  = 1000*exp(-0.15*(d-10));
yy = 1000*exp(-0.16*(dd-10));

%% Graph
f1 = figure(1);
h  = plot( d, y,'b-', dd, yy, 'r-.o');
axis([9.5 22.5 0 1200]);
set(h(1),'LineWidth',2);
set(h(2),'LineWidth',2);
h1 = gca;
set(h1, 'Color', 'y', 'FontSize', 12, 'FontWeight', 'bold');
set(h1, 'XTick',[10 14 16 20 22])
set(h1, 'XTickLabel',{'Start','P1','P2','Edge','End'},'FontSize',12,'FontWeight','bold')
xlabel('\rmDistance \delta ({\itcm})','FontSize',16);
ylabel('\rmIntensity  \Gamma ({\itlux})');
title('\fontname{times}\fontsize{18}{\bfL}\fontsize{16}{\rmight} \fontsize{18}{\bfI}\fontsize{16}{\rmntensity}',...
    'Color',[0 0 1]);
a = legend('theory','experiment');
set(a,'Color','w');
grid on;
% Create textarrow
annotation(f1,'textarrow',[0.632575757575758 0.492424242424242],...
    [0.544098039215686 0.411764705882353],'TextEdgeColor',[0 0 1],...
    'TextBackgroundColor',[1 1 1],...
    'FontSize',12,...
    'String',{'theorectical curve','1000 x e^{-0.15x(\delta-10)}'});

% Create textarrow
annotation(f1,'textarrow',[0.403409090909091 0.509469696969697],...
    [0.264705882352941 0.36078431372549],'TextEdgeColor',[1 0 0],...
    'TextBackgroundColor',[1 1 1],...
    'FontSize',12,...
    'String',{'experimental','data'});

axes('position',[.83  .84 .05 .05])
h1 = imshow('korea.png'); set( h1, 'AlphaData', 0.8');