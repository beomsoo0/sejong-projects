P=5000; r=0.085; ta=17; n=12;
B = P*(1+r)^ta;
t = log(B/P)/(n*log(1+r/n));
years = fix(t);
months = ceil((t-years) * 12);
years
months