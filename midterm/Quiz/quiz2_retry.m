input = xlsread('quiz3.xlsx');
fprintf("데이터 길이: %d개\n", length(input));
fprintf("평균: %f\n", mean(input));
fprintf("표준편차: %f\n", std(input));
fprintf("중앙값: %f\n", median(input));