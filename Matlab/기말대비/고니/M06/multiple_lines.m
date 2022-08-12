% plotting matrix
Y = rand(10,5);
figure(1);
plot(Y); grid on;
xlabel('index'); ylabel('value');
legend('data1', 'data2', 'data3', 'data4', 'data5' );
