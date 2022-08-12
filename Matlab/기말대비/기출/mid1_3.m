clear
clc
x = [4.5 5 -16.12 21.8 10.1 10 -16.11 5 14 -3 3 2];
for i=1:length(x)
    for j=2:length(x)-i+1
        if x(j-1)>x(j)
            temp = x(j-1);
            x(j-1) = x(j);
            x(j) = temp;
        end
    end
end
x