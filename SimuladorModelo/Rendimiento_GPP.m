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
% Gilberto Reynoso-Meza  - (gilreyme@upv.es)
%%
%% SOBRE LA FUNCIÓN
%
% [Rendimiento, R, Zonas]=GPP_Performance(J,Phy,Labels) es la función que determina el
% rendimiento global para una propuesta de controlador y/o propuesta de
% modelo del Cuadrirrotor.
% 
%  J          : Es un vector fila con "Nind" índices de desempeño a evaluar.
%               Puede aceptar varias filas para evaluarlas de forma
%               independiente
% Phy         : Es una matriz de "Nind" filas y 6 columnas que determinan los
%               rangos de preferencias para cada uno de los objetivos en J.
% Labels      : Etiquetas para cada uno de los objetivos. Puede ser
%               omitido.
% Rendimiento : El rendimiento global del objetivo, de acuerdo a las
%               preferencias establecidas en "Phy".
%  R          : Rango (en porcentaje) que un objetivo tiene dentro de su preferencia.
% Zonas       : Zona en la que se encuentra un objetivo determinado.
%
%%
%% REFERENCIAS
%
% Para mayor referencia en como construir la matriz de preferencias "Phy" y
% como funciona GPP se invita a consultar:
%
% J. Sanchis, M. Martínez, X. Blasco, G. Reynoso. Modelling preferences in
% multi-objective engineering design. Engineering Applications of 
% Artificial Intelligence. Vol. 23, num. 8, pp. 1255 - 1264, 2010 
% (ISSN:0952-1976).
%
%%
%% ADVERTENCIA
%
% Este script no debe ser alterado, ya que será utilizado tal y como está
% para evaluar a cada uno de los competidores en el benchmark.
% Los organizadores se reservan el derecho a modificarlo para corregir
% cualquier fallo o "bug" que pudiera surgir. En tal caso, se hará del
% conocimiento de todos los concursantes dichas modificaciones.
%
%%
%% Rendimiento_GPP

function [Rendimiento R Zona]=Rendimiento_GPP(J,Phy,Etiquetas)

if nargin==2
    Etiquetas={' ',' ',' '; ' ', ' ', ' '};
end

Population=size(J,1);            % Número de vectores objetivo.
Nobj=size(J,2);                  % Número de objetivos.
F=zeros(Population,Nobj);        % Inicialización de F.
R=zeros(Population,Nobj);        % Inicialización de R.
Zona=cell(Population,Nobj);
Rendimiento=zeros(Population,1); % Inicialización de Rendimiento.
N = 1;                           % Curvatura en GPP.
                                 % N=1 --> Rectas.
                                 % N=2 --> Parábolas....

% El offset ha sdo definido en la siguiente forma para reforzar la
% interpretabilidad del indicador de rendimiento GPP. Un Rendimiento>100
% significa que alguno de los indicadores de desempeño se encuentra en la
% zona "Indeseable". Un Rendimiento=100, significa que todos los
% indicadores se encuentran en la frontera "Tolerable|Indeseable" para
% todos sus indicadores. Un Rendimiento=0, significa un rendimiento
% perfecto, i.e. seguimiento perfecto de la trayectoria de control en el
% tiempo de recorrido mínimo, con un modelo que representa perfectamente al
% cuadrirrotor.

%       [-----HD----](-----D----](-----T----](-----U----](-----HU---](---->
offset=[0,       1/Nobj^2,   1/Nobj^0,     Nobj^2,     Nobj^4,    Nobj^6];
offset=100*offset/(Nobj^2*(Nobj+1));


% Así mismo, para complementar la regla heurística "One-Vs-Others", se ha
% modificado el offset que se suma en cada uno de los rangos de
% preferencia.

for population=1:Population
    for nobj=1:Nobj
        if J(population,nobj)>Phy(nobj,1) && J(population,nobj)<=Phy(nobj,2)     % Tenemos un valor altamente deseable
            F(population,nobj)=offset(1)*(Nobj+1)+ (offset(2)-offset(1))*((J(population,nobj)-Phy(nobj,1))/(Phy(nobj,2)-Phy(nobj,1)))^N;
            R(population,nobj)=100*(J(population,nobj)-Phy(nobj,1))/(Phy(nobj,2)-Phy(nobj,1));
            Zona{population,nobj}='AD - Altamente Deseable';
        elseif J(population,nobj)>Phy(nobj,2) && J(population,nobj)<=Phy(nobj,3) % Tenemos un valor deseable
            F(population,nobj)=offset(2)*(Nobj+1)+ (offset(3)-offset(2))*((J(population,nobj)-Phy(nobj,2))/(Phy(nobj,3)-Phy(nobj,2)))^N;
            R(population,nobj)=100*(J(population,nobj)-Phy(nobj,2))/(Phy(nobj,3)-Phy(nobj,2));
            Zona{population,nobj}='D - Deseable';
        elseif J(population,nobj)>Phy(nobj,3) && J(population,nobj)<=Phy(nobj,4) % Tenemos un valor tolerable
            F(population,nobj)=offset(3)*(Nobj+1)+ (offset(4)-offset(3))*((J(population,nobj)-Phy(nobj,3))/(Phy(nobj,4)-Phy(nobj,3)))^N;
            R(population,nobj)=100*(J(population,nobj)-Phy(nobj,3))/(Phy(nobj,4)-Phy(nobj,3));
            Zona{population,nobj}='T - Tolerable';
        elseif J(population,nobj)>Phy(nobj,4) && J(population,nobj)<=Phy(nobj,5) % Tenemos un valor indeseable
            F(population,nobj)=offset(4)*(Nobj+1)+ (offset(5)-offset(4))*((J(population,nobj)-Phy(nobj,4))/(Phy(nobj,5)-Phy(nobj,4)))^N;
            R(population,nobj)=100*(J(population,nobj)-Phy(nobj,4))/(Phy(nobj,5)-Phy(nobj,4));
            Zona{population,nobj}='I - Indeseable';
        elseif J(population,nobj)>Phy(nobj,5) && J(population,nobj)<=Phy(nobj,6) % Tenemos un valor altamente indeseable.
            F(population,nobj)=offset(5)*(Nobj+1)+ (offset(6)-offset(5))*((J(population,nobj)-Phy(nobj,5))/(Phy(nobj,6)-Phy(nobj,5)))^N;
            R(population,nobj)=100*(J(population,nobj)-Phy(nobj,5))/(Phy(nobj,6)-Phy(nobj,5));
            Zona{population,nobj}='AI - Altamente Indeseable';
        elseif J(population,nobj)>Phy(nobj,6)                                    % Tenemos un valor fuera de toda consideración.
            F(population,nobj)=offset(6)*(Nobj+1);
            R(population,nobj)=100*(J(population,nobj)-Phy(nobj,5))/(Phy(nobj,6)-Phy(nobj,5));
            Zona{population,nobj}='FUERA DE TODA CONSIDERACION!!!';
        end        
    end
    Rendimiento(population,1)=sum(F(population,:));        
end

%%
%% Desplegamos en pantalla:

for population=1:Population
    disp(['Vector objetivo ' num2str(population) ' : valor GPP : ' num2str(Rendimiento(population,1))]);
    Jind=J(population,:);
    Rind=R(population,:);
    for nobj=1:Nobj
       if Jind(1,nobj)<=Phy(nobj,2)
           disp(['---J' num2str(nobj) ': ' Etiquetas{1,nobj} ' = ' num2str(Jind(1,nobj)) ' ' Etiquetas{2,nobj} ' ---> AD - Altamente Deseable (' num2str(Rind(1,nobj)) '%)']);
       elseif Jind(1,nobj)>Phy(nobj,2) && Jind(1,nobj)<=Phy(nobj,3)
           disp(['---J' num2str(nobj) ': ' Etiquetas{1,nobj} ' = ' num2str(Jind(1,nobj)) ' ' Etiquetas{2,nobj} ' ---> D - Deseable (' num2str(Rind(1,nobj)) '%)']);
       elseif Jind(1,nobj)>Phy(nobj,3) && Jind(1,nobj)<=Phy(nobj,4)
           disp(['---J' num2str(nobj) ': ' Etiquetas{1,nobj} ' = ' num2str(Jind(1,nobj)) ' ' Etiquetas{2,nobj} ' ---> T - Tolerable (' num2str(Rind(1,nobj)) '%)']);
       elseif Jind(1,nobj)>Phy(nobj,4) && Jind(1,nobj)<=Phy(nobj,5)
           disp(['---J' num2str(nobj) ': ' Etiquetas{1,nobj} ' = ' num2str(Jind(1,nobj)) ' ' Etiquetas{2,nobj} ' ---> I - Indeseable (' num2str(Rind(1,nobj)) '%)']);
       elseif Jind(1,nobj)>Phy(nobj,5)
           disp(['---J' num2str(nobj) ': ' Etiquetas{1,nobj} ' = ' num2str(Jind(1,nobj)) ' ' Etiquetas{2,nobj} ' ---> AI - Altamente Indeseable (' num2str(Rind(1,nobj)) '%)']);
       end           
    end
end

%% Registro de modificaciones:
% V.Nov_12, CPOH 2012.