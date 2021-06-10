clear
clc
load('score_Table.mat')

sub_mean = mean(score)
sub_min = min(score)
sub_max = max(score)
sub_std = std(score)

score_n_mean = score;
score_n_mean(end + 1, :) = sub_avg

ceil(6 * rand(1))

dice_try = ceil(6 * rand(1, 10000));

dice_mean = mean(dice_try)
dice_std = std(dice_try)

