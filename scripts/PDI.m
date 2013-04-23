%% Sacar maximos y minimos de las señales x e y

maxvx = max(scVar.signals(1,1).values(:,2));
minvx = min(scVar.signals(1,1).values(:,2));

maxvy = max(scVar.signals(1,2).values(:,2));
minvy = min(scVar.signals(1,2).values(:,2));

maxax = max(scVar.signals(1,1).values(:,6));
minax = min(scVar.signals(1,1).values(:,6));

maxay = max(scVar.signals(1,2).values(:,6));
minay = min(scVar.signals(1,2).values(:,6));

maxEr = max(modulo_vE.signals(1,1).values(:,1));

str = sprintf('%0.2f < vx > %0.2f', minvx, maxvx);
disp(str);
str = sprintf('%0.2f < ax > %0.2f', minax, maxax);
disp(str);
str = sprintf('%0.2f < vy > %0.2f', minvy, maxvy);
disp(str);
str = sprintf('%0.2f < ay > %0.2f', minay, maxay);
disp(str);

%% Máximo error cometido durante el recorrido
str = sprintf('Maximo error = %0.2f', maxEr);
disp(str);

%% Valores de la consigna durante el recorrido

Cx = vCons.signals.values(:,1);
Cy = vCons.signals.values(:,2);

maxCX = max(abs(Cx));
maxCY = max(abs(Cy));
medCX = mean(abs(Cx(2:end)));
medCY = mean(abs(Cy(2:end)));

str = sprintf('Consigna max en X = %0.2f', maxCX);
disp(str);
str = sprintf('Consigna max en Y = %0.2f', maxCY);
disp(str);
str = sprintf('Consigna media en X = %0.2f', medCX);
disp(str);
str = sprintf('Consigna media en Y = %0.2f', medCY);
disp(str);

% iter = ceil(maxC*20);
% moda = zeros(iter,1);
% 
% for i=1:1:iter
%     aux = i*0.05;
%     for j=1:n
%         if (Consigna(j,1) < aux) && (Consigna(j,1) > (aux - 0.05))
%             moda(i,1) = moda(i,1)+1;
%         end
%     end
%  end
