%% CEA: Concurso de Ingenier�a de Control 2013 (V.Nov_12), CPOH-UPV 2012
% Control aut�nomo del seguimiento de trayectorias de un veh�culo
% cuatrirrotor
% http://www.ceautomatica.es/og/ingenieria-de-control/benchmark-2012-2013
%%
%% CPOH 2011
% Grupo de Control Predictivo y Optimizaci�n Heur�stica
% Instituto Universitario de Autom�tica e Inform�tica Industrial
% Universitat Polit�cnica de Val�ncia
% Valencia, Espa�a
%%
%% Autores
% Xavier Blasco Ferragud - (xblasco@isa.upv.es)
% Sergio Garc�a-Nieto    - (sergarro@isa.upv.es)
% Gilberto Reynoso-Meza  - (gilreyme@upv.es)


%% Simulaci�n controlador
% ruta=[0 10;0 10;0 10;0 10;0 10;0 10;0 10;0 10;0 10;0 10;];
% ruta=[0 2;8 0;6 -8;0 -7;-8 -8;-7 0;0 1;8 -1]; % Prueba trayectos predomina 'X'
% ruta=[1 -6;-5 -7;-13 -6;-12 0]; % Prueba de trayectos b�sicos
% ruta=[3 2;1 -6;-5 -7;-13 -6;-12 0]; % Prueba de trayectos b�sicos FAIL!!
ruta=[12 0;12 5;7 -5;-1 4;-6 -5;-2 0]; % Trayecto original
% ruta=[12 0;12 12;0 12;0 0]; % Trayecto cuadrado, horiz. y vert.
%ruta=intermedio(ruta,2);% Esta funcion a�ade puntos intermedios.
radio=0.1;
sim('simuladorControlCuatrirrotor')

%% PDI
% crea indicadores acerca de los maximos y medios de la consigna durante el
% recorrido
pdi;


%% Representaci�n gr�fica y c�lculo de indicadores
indicadores=pintascdata(scdata,ruta,radio,scVar,pos,vE,modulo_vE,modulo_vCons,vCons);


%% Evaluaci�n 

% clc;
disp('************ Rendimiento GPP **************')
%Preparamos el vector para evaluar rendimiento
J=[indicadores.dmedia, indicadores.dmax, indicadores.tiempoRecorrido];
taux=indicadores.tiempoMin;

%Preparamos la matriz de preferencias
%          [-----AD----](-----D----](-----T----](-----I----](-----AI---](---->
PhyMatrix=[0         0.0500      0.1000      0.1500      0.2500      0.500;
           0         0.1000      0.1500      0.2500      0.5000      1.000;
           taux         2*taux    2.5*taux      4*taux      5*taux     9*taux];

Etiquetas={'Distancia Media','Distancia M�xima','Tiempo de Recorrido';
               'metros',           'metros',        'segundos'};
       
%Evaluamos

[GPP, Porcentajes, Zonas]=Rendimiento_GPP(J,PhyMatrix,Etiquetas)

%% Registro de modificaciones:
% V.Nov_12, CPOH 2012.