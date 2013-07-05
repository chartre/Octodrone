function er (x0,y0,x,y)
%% er (x0,y0,x,y)
format shortg
m = (y-y0)/(x-x0);
ti =-(m*x0)+y0;
str = sprintf('y = %d*x +(%d)',m,ti);
disp(str)
