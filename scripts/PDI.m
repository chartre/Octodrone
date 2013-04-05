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

Consigna = zeros(size(scVar.signals(1,1).values(:,1),1),1);
n = size(scVar.signals(1,1).values(:,1),1);
for i=1:n % obtiene la distancia de la consigna en cada momento
    Cx = scVar.signals(1,1).values(i,4) - scVar.signals(1,1).values(i,1);
    Cy = scVar.signals(1,2).values(i,4) - scVar.signals(1,2).values(i,1);
    
    Consigna (i,1) = norm(Cx,Cy);
end
maxC = max(Consigna);
medC = mean(Consigna(2:end));

str = sprintf('Consigna max = %0.2f', maxC);
disp(str);
str = sprintf('Consigna media = %0.2f', medC);
disp(str);

iter = ceil(maxC*20);
moda = zeros(iter,1);

for i=1:1:iter
    aux = i*0.05;
    for j=1:n
        if (Consigna(j,1) < aux) && (Consigna(j,1) > (aux - 0.05))
            moda(i,1) = moda(i,1)+1;
        end
    end
end
