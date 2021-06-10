clear clc
T = input('온도를 화씨 단위로 입력하세요');
R = input('상대 습도를 % 단위로 입력하세요');
HI=-42.379+2.04901523*T+10.14333127*R-0.22475541*T*R-6.83783e-3*T^2 - 5.481717e-2*R^2+1.22874e-3*T^2*R + 8.5282e-4*T*R^2-1.99e-6*T^2*R^2;
fprintf("The Heat Index temperature is: %d\n", round(HI))