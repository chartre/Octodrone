%% Sacar maximos y minimos de las señales x e y

maxvx = max(scVar.signals(1,1).values(:,2));
minvx = min(scVar.signals(1,1).values(:,2));

maxvy = max(scVar.signals(1,2).values(:,2));
minvy = min(scVar.signals(1,2).values(:,2));

maxax = max(scVar.signals(1,1).values(:,6));
minax = min(scVar.signals(1,1).values(:,6));

maxay = max(scVar.signals(1,2).values(:,6));
minay = min(scVar.signals(1,2).values(:,6));

str = sprintf('%0.2f < vx > %0.2f', minvx, maxvx);
disp(str);
str = sprintf('%0.2f < ax > %0.2f', minax, maxax);
disp(str);
str = sprintf('%0.2f < vy > %0.2f', minvy, maxvy);
disp(str);
str = sprintf('%0.2f < ay > %0.2f', minay, maxay);
disp(str);
