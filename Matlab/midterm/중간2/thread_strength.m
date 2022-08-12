T = xlsread('thread_strength.xlsx');
n = [0 0 0 0 0 0 0];
for k=1:length(T)
    n(T(k) - 90) = n(T(k) - 90) + 1;
end
fprintf('실의 대표 강도는 %d [N]이다. 총 %d회 실험 중 %d회가 나왔다\n', max(n) + 90, length(T), max(n))