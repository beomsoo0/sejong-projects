clear
clc

for y =1:4
    for x =1:3
        arr(y,x) = 4*x + 6*(y-1);
    end
end
arr;

sum(arr)
sum2 = [0 0 0];
for x = 1:3
    for y = 1:4
        sum2(x) = sum2(x) + arr(y, x);
    end
end
sum2