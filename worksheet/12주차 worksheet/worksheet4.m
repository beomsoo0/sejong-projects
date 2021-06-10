clear
clc

f = [2 2 -2 -2];
g = [2 -2];
con = conv(f,g)
decon = deconv(con, f)
g == decon
