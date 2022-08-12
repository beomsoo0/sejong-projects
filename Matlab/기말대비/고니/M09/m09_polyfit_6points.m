%% �ּ��ڽ¹��� �̿��� ������ ���ÿ��� ���� ���׽��� ����
% 1�� �����Ŀ� ���� ǥ���Ǵ� ������ ������ �� ������ ������ ����� ���
% �ʿ� �̻��� ���� ���׽��� �̿��Ͽ� ������ ������ �ϴ� ��� ���� �����ʹ�
% �ٻ��ϰ� ��Ÿ������ ���� ���� ��Ģ�� �ٸ� �� �ֽ��ϴ�.
%

%% ���� ���� ������
x = [1 3 4 6 8 10];
y = 2.5*x + 2 + 3*randn(size(x));

figure(1);
plot(x,y,'ro','LineWidth',2,'MarkerSize',10);
grid; hold on; axis([0 11 -5 30]);

%% ���� �������� �̿��� ������ ���� ���
x1 = 0:0.01:11;
linespec = ['b-','r-','k-'];
for n=1:2:5
    p = polyfit(x,y,n);
    y1 = polyval(p,x1);
    plot(x1,y1,linespec(n), 'LineWidth', 2);
end
hold off;
legend('Experiment','1st order poly', '3rd order poly',...
    '5th order poly', 'Location', 'SouthEast');
xlabel('$x$', 'Interpreter', 'latex');
ylabel('$y$', 'Interpreter', 'latex');
