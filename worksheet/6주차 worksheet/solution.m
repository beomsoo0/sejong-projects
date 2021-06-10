clear
clc
x = 1:7;
y1=[0 0.48 0.84 1 0.91 0.6 0.14];
y2=[0.2 0.5 1 0.84 0.6 0.32 0.09];
y3=[0.5 0.24 0.31 0.7 1 0.8 0.44];
plot(x, y1, 'g:*', 'LineWidth', 1, 'MarkerSize', 9, x, y2, 'g:*', 'LineWidth', 1, 'MarkerSize', 12);
hold on
plot(x, y3,'--r', 'LineWidth', 2);
hold off