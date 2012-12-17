function dibujaEnsayo(exp,ds)
%CEA: Concurso de Ingenieria de Control 2013 (V. Nov_12), CPOH-UPV 2012
%Control autonomo del seguimiento de trayectorias de un vehiculo cuatrirrotor
%http://www.ceautomatica.es/og/ingenieria-de-control/benchmark-2012-2013
%
% dibujaEnsayo(exp,ds)
%
% 'exp' tiene 7 columnas.
%
%   col 1: tiempo en segundos
%   col 2: posición x en metros
%   col 3: velocidad x en metros/segundos
%   col 4: posición y en metros
%   col 5: velocidad y en metros/segundos
%   col 6: RefPitch entre -1 y 1
%   col 7: RefRoll entre -1 y 1
%


% 'ds' dimensiones de la sala
%  [xmin, xmax, ymin, ymax]

if nargin==1
    % Dimensión sala 2013
    ceroRel=[20 5];
    dimAbsoluta=[0 25 0 20];
    ds=dimAbsoluta-[ceroRel(1) ceroRel(1) ceroRel(2) ceroRel(2)];
end

figure
subplot(6,1,1)
plot(exp(:,1),exp(:,2))
title('x')
subplot(6,1,2)
plot(exp(:,1),exp(:,3))
title('vx')
subplot(6,1,3)
plot(exp(:,1),exp(:,4))
title('y')
subplot(6,1,4)
plot(exp(:,1),exp(:,5))
title('vy')
subplot(6,1,5)
plot(exp(:,1),exp(:,6))
title('RefPitch')
subplot(6,1,6)
plot(exp(:,1),exp(:,7))
title('RefRoll')
xlabel('sec')

figure
plot(exp(:,2),exp(:,4))
rectangle('position',[ds(1) ds(3) ds(2)-ds(1) ds(4)-ds(3)],...
    'LineWidth',4,'EdgeColor','r')

title('Trayectoria xy')