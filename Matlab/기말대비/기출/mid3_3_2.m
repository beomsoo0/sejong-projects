clear clc
y = xlsread('thread_strength.xlsx')
val_91 = length(find(y==91));
val_92 = length(find(y==92));
val_93 = length(find(y==93));
val_94 = length(find(y==94));
val_95 = length(find(y==95));
val_96 = length(find(y==96));

max = 0
maxnum = 0
if val_91 > val_92
    max = val_91;
    maxnum = 91;
else
    max = val_92;
    maxnum = 92;
end
if val_93 > max
    max = val_93;
    maxnum = 93;
end
if val_94 > max
    max = val_94;
    maxnum = 94;
end
if val_95 > max
    max = val_95;
    maxnum = 95;
end
if val_96 > max
    max = val_96;
    maxnum = 96;
end
fprintf('실의 대표 강도는 %d [N]이다. 총 %d회 실험 중 %d회가 나왔다.\n\n',maxnum, length(y), max);