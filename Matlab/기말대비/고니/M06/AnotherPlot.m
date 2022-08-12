t1=[floor(0:-2:-20);0:4:40];
t2=[floor(0:-2:-20);1:4:41];
t3=[floor(2:2:20);2:4:38];
t4=[floor(2:2:20);3:4:39];
t5=[floor(1:2:19);2:4:38];
t6=[floor(1:2:19);3:4:39];
m=[t1 t2 t3 t4];n=[t1 t2 t5 t6];
[tmp1,idx1]=sort(m(2,:));ms=m(:,idx1);
[tmp1,idx2]=sort(n(2,:));ns=n(:,idx2);
x=ns(1,2:end);y=ms(1,1:end-1);
figure(1);
plot(x,y,'b-o')
%%
figure(2), stem(x);
%%
xx = 1:20; xx1 = xx .* (-1).^(xx+1);
xx2 = repmat(xx1,2,1); xx3 = reshape(xx2, 1,[]);
xxx = [ 0 xx3 ];
figure(3), stem(xxx);
%%
figure(4), stem(y);
%%
y0 = 2:2:20; 
y1 = reshape(repmat(y0,2,1), 1, []);
n1 = 1:length(y1);
y2 = y1 .* (-1).^(n1+1);
y3 = reshape(repmat(y2,2,1), 1, []);
y  = [0 0 y3(1:end-1)];
figure(5), stem(y);