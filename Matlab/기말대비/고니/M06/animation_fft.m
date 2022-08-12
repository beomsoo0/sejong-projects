for k = 1:16
	plot(fft(eye(k+16)))
	axis equal
	M(k) = getframe;
end
movie(M,1);
%%
h = uicontrol('style','slider','position',...
	[10 50 20 300],'Min',1,'Max',16,'Value',1);
for k = 1:16
	plot(fft(eye(k+16)))
	axis equal
	set(h,'Value',k)
	M(k) = getframe(gcf);
end
clf
axes('Position',[0 0 1 1])
movie(M,1);