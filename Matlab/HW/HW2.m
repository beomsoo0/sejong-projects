clear
clc
A = [3 1 1 2 1; 1 2 1 3 1; 1 1 0 3 3; 2 0 3 1 2; 1 2 3 0 2];
B = 16 * [128; 118; 112; 112; 104];
x = inv(A) * B