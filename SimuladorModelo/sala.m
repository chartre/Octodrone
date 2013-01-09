%% CEA: Concurso de Ingeniería de Control 2013 (V.Nov_12), CPOH-UPV 2012
% Control autónomo del seguimiento de trayectorias de un vehículo
% cuatrirrotor
% http://www.ceautomatica.es/og/ingenieria-de-control/benchmark-2012-2013
%%
%% CPOH 2012
% Grupo de Control Predictivo y Optimización Heurística
% Instituto Universitario de Automática e Informática Industrial
% Universitat Politècnica de València
% Valencia, España
%%
%% Autores
% Xavier Blasco Ferragud - (xblasco@isa.upv.es)
% Sergio García-Nieto    - (sergarro@isa.upv.es)
% Gilberto Reynoso-Meza  - (gilreyme@upv.es)%
% pintaResultExp(exp)

function ens=sala(ens,limites)

Lx=limites(1);
Ux=limites(2);
Ly=limites(3);
Uy=limites(4);

choca=min([find(ens(:,2)<=Lx,1)
find(ens(:,2)>=Ux,1)
find(ens(:,4)<=Ly,1)
find(ens(:,4)>=Uy,1)]);

if ~isempty(choca)
    disp('Warning: el parato ha salido de la zona de control')
  %ens(choca:end,2:5)=repmat([ens(choca,2) 0 ens(choca,4) 0],size(ens,1)-choca+1,1);
else
    ens=ens;
end

%% Registro de modificaciones:
% V.Nov_12, CPOH 2012.