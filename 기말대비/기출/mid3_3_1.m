clear clc
y = xlsread('thread_strength.xlsx');
x = [91:96];
[h_count, h_centers] = hist(y, x);
[max, max_idx] = max(h_count);
fprintf('실의 대표 강도는 %d [N]이다. 총 %d회 실험 중 %d회가 나왔다.\n\n',h_centers(max_idx), length(y), max);