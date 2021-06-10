clear, clc;
syms i t R C L
i=dsolve('L*D2i+R*Di+1/C*i=10','i(0)=0','Di(0)=8');
iNb=subs(i,{L,R,C},{3,10,80*10^-6});
ezplot(iNb,[0,1]);
xlabel('Time (s)');
ylabel('i (A)');
text(0.6,0.09, '부족제동' );
