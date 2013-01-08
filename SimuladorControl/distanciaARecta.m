%% CEA: Concurso de Ingenier�a de Control 2013 (V.Nov_12), CPOH-UPV 2012
% Control aut�nomo del seguimiento de trayectorias de un veh�culo
% cuatrirrotor
% http://www.ceautomatica.es/og/ingenieria-de-control/benchmark-2012-2013
%%
%% CPOH 2012
% Grupo de Control Predictivo y Optimizaci�n Heur�stica
% Instituto Universitario de Autom�tica e Inform�tica Industrial
% Universitat Polit�cnica de Val�ncia
% Valencia, Espa�a
%%
%% Autores
% Xavier Blasco Ferragud - (xblasco@isa.upv.es)
% Sergio Garc�a-Nieto    - (sergarro@isa.upv.es)
% Gilberto Reynoso-Meza  - (gilreyme@upv.es)

%% Funci�n distanciaARecta()

function d=distanciaARecta(pto,recta)
% Calcula la distancia de un punto a una recta
% pto=[xa,ya]
% recta=[m b]  -> y=m*x+b
%   Nota: si la recta es vertical poner pasando por x1 poner recta=[inf,x1]
% d=distanciaARecta(pto,recta)
%
if recta(1)==inf
    d=pto(1)-recta(2);
else
    d=abs(recta(1)*pto(1)-pto(2)+recta(2))/sqrt(recta(1)^2+1);
end


%% Registro de modificaciones:
% V.Nov_12, CPOH 2012