d  = 10:0.1:22;
dd = 10:2:22;
y  = 1000*exp(-0.15*(d-10));
yy = 1000*exp(-0.16*(dd-10));
figure(1),h=plot(d,y,'b-',dd,yy,'r-.o');
axis([8 24 0 1200]);
set(h(1),'LineWidth',2);
set(h(2),'LineWidth',2);
h1 = gca;
set(h1, 'Color', 'Green');
set(h1,'XTick',[10 14 16 20 22])
set(h1,'XTickLabel',{'Start','P1','P2','Edge','End'},'FontSize',12,'FontWeight','bold')
xlabel('\rmDistance \delta ({\itcm})','FontSize',16);
ylabel('\rmIntensity  \Gamma ({\itlux})');
title('\fontname{times}\fontsize{18}{\bfL}\fontsize{16}{\rmight} \fontsize{18}{\bfI}\fontsize{16}{\rmntensity \Gamma_1 ={\itf}(\delta)=1000{\ite}^{\delta-10}}',...
    'Color',[0 0 1]);
a = legend('Theory','Experiment');
set(a,'Color','red');
grid on;
text(16.2,670,'\fontname{times}\Sigma^{10}_{i=1}{\itx_i} \fontname{Helvetica}x \fontname{times}{\itA^{2\pi^{2-i}}_{i,2}}');

