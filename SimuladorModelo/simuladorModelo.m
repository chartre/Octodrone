%% CEA: Concurso de Ingeniería de Control 2013 (V.Dic_12), CPOH-UPV 2012
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
% Gilberto Reynoso-Meza  - (gilreyme@upv.es)

%% Experimento

load exp_ini_fase1.txt; % carga el txt con los datos para trabajar con el.
exp=exp_ini_fase1; % crea una copia del txt para no machacar el original y que siga estando disponible

sim('ComparadorModelo_continuo_separado'); % simula el modelo de "ComparadorModelo_continuo.mdl"
% cero=[20 5];
% dimSala=[0 25 0 20];
% indModelo=pintaResultExp(ResultExp,cero,dimSala);
indModelo=pintaResultExp(ResultExp); % ejecuta "pintaResultExp" pasandole lo que se supone que es el resultado de la simulacion (ResultExp).

%% Evaluación 

%clc; % despeja la ventana de comandos
disp('************ Rendimiento GPP **************')
%Preparamos el vector para evaluar rendimiento
J=[indModelo.dxmedio, indModelo.dymedio, indModelo.dxmax, indModelo.dymax];

%Preparamos la matriz de preferencias
%          [-----AD----](-----D----](-----T----](-----I----](-----AI---](---->
PhyMatrix=[0         0.2000      0.6000      1.0000      1.5000      2.500;
           0         0.2000      0.6000      1.0000      1.5000      2.500;
           0         0.5000      1.8000      3.5000      5.5000      8.000;
           0         0.5000      1.8000      3.5000      5.5000      8.000;];

Etiquetas={'Distancia X Media','Distancia Y Media', 'Distancia X Máxima','Distancia Y Máxima';
               'metros',           'metros',               'metros',           'metros'};
       
%Evaluamos

[GPP, Porcentajes, Zonas]=Rendimiento_GPP(J,PhyMatrix,Etiquetas)

%% Registro de modificaciones:
% V.Nov_12, CPOH 2012.