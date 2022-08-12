arr = [77 66 72 75 90 86 58 98 89 59];

mean = 0;
sum = 0;
for i=1:length(arr)
    mean = mean + arr(i);
end
mean = mean / length(arr);

fprintf("평균 점수 : %d점\n", mean); 
fprintf("평균 점수를 넘는 학생 수 : %d명\n", length(find (arr > mean)));
    