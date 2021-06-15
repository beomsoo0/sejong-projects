PopData = [ 2308, 5561, 517, 912, 398, 51 ];
figure('Position', [100, 400, 900, 400] );
subplot(1,2,1); barh(PopData); grid on;
ax = gca; ax.YTickLabel = {'Africa', 'Asia','Europe', 'Latin America', ...
    'North America', 'Oceania'};
ax.YDir = 'reverse';
xlabel('Milions');
subplot(1,2,2); pie(PopData);
legend( 'Africa', 'Asia','Europe', 'Latin America', 'North America', ...
    'Oceania', 'Location', 'SouthEast' );
