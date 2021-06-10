x = [4.5 5 -16.12 21.8 10.1 10 -16.11 5 14 -3 3 2];
for n=length(x):-1:2
    for m =1:n-1
        while x(m) > x(m+1)
            x([m, m+1]) = x([m+1, m]);
        end
    end
end
x