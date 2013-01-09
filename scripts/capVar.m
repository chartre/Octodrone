%% Script de captura de Variables.
% Generamos dentro del workspace las variables correspondientes para...
% operar con ellas en los experimentos y el simulink.
% 
% Se procurará mantener esta función única para el desarrollo...
% de todas las variables.
%

%% Cargamos datos de fichero y seccionamos en columnas

load exp_ini_fase1.txt;
exp=exp_ini_fase1;
t=exp_ini_fase1(:,1);
x=exp_ini_fase1(:,2);
vx=exp_ini_fase1(:,3);
y=exp_ini_fase1(:,4);
vy=exp_ini_fase1(:,5);
refPitch=exp_ini_fase1(:,6);
refRoll=exp_ini_fase1(:,7);

% esto es una prueba del Github
