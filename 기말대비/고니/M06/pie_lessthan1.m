grades = [ 11 18 26 9 5]*0.01;
figure(2); 
p = pie(grades,[ 0 0 0 1 0]);
p(7).LineStyle = '-.';
p(8).String = '9% (Science)';
p(8).Color = [1 0 0];
