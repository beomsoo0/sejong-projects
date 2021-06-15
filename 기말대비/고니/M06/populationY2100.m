pop = [ 2308 5561 517 912 398 51 ];
flag = [ 0 0 1 0 0 0 ];
figure(1), pie(pop, flag);
legend('Africa', 'Asia', 'Europe', ...
    'L. America', 'N. America', 'Oceania', ...
    'Location', 'SouthEast');
%%
figure(2), b = bar(pop);


