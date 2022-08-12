clear
clc
data = xlsread('score.xlsx');
sum = sum(data(:, 2:end),2);
new_data = data;
new_data(:, end+1) = sum;
mean = mean(new_data(:, 2:end));
max = max(new_data(:, 2:end));
min = min(new_data(:, 2:end));
new_data(end + 1:end + 3,1) = 100;
new_data(end - 2, 2:end) = mean;
new_data(end - 1, 2:end) = max;
new_data(end, 2:end) = min;