% Subplot Demo
y = floor(10*rand(1,6))+3;
x = [1:length(y)] - 1;
figure(1);
subplot(2,3,1); 
plot(x,y,'b-'); axis([-0.5 5.5 0 15]);
subplot(2,3,2); 
stem(x,y,'filled'); axis([-0.5 5.5 0 15]);
subplot(2,3,3); 
stairs(x,y,'b-'); axis([-0.5 5.5 0 15]);
subplot(2,3,4); 
bar(x,y,0.75); axis([-0.5 5.5 0 15]);
subplot(2,3,5); 
pie(y,[0 0 0 0 0 1]);
subplot(2,3,6); 
polar([x x(1)]*2*pi/6,[y y(1)],'b-');
