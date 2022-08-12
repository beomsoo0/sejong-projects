clear
clc
input = xlsread('quiz3.xlsx');
fprintf("데이터 길이:%d개\n", length(input));
fprintf("평균:%f개\n", mean(input));
fprintf("표준편차:%f개\n", std(input));
fprintf("중앙값:%f개\n", median(input));