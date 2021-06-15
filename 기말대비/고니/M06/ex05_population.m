%% Wold Population in a Pie Chart
pop  = [4140336501 994527534 738523843 528720588 385742554 36102071 ];
flag = [         0         1         0         0         0        0 ];
figure(1), pie(pop, flag);
legend('Asia', 'Africa', 'Europe', ...
    'N. America', 'S. America', 'Oceania', ...
    'Location', 'NorthWest');
title('World Population in 2011');

%% Wold Population in a Bar Chart
total = sum(pop);
ratio = 100 * pop/total;
figure(2), b = bar(pop); hold on;
title('World Population in 2011');
set( gca, ...
    'XTickLabel',{'Asia','Africa','Europe','N. America','S. America','Oceania'},...
    'XTick',[1 2 3 4 5 6]);
box(gca,'off');
for k=1:6
    text(k-0.2, pop(k)+0.1e9, sprintf('%2.0f%%', ratio(k)) );
end

hold off;



