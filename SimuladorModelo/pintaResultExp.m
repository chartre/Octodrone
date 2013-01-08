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
%

%% Función pintaResultExp()

function indicadoresModelo=pintaResultExp(datos,cero,dimAbsSala)
% indicadoresModelo=pintaResultExp(exp,cero,dimAbsSala)
%    exp: variable con los resultados de ComparadorModelo_continuo.mdl
%    indicadoresModelo: estructura con los indicadores para evaluación
%      indicadoresModelo.dxmedio : Valor medio error x
%      indicadoresModelo.dymedio : Valor medio error y
%      indicadoresModelo.dxmax : Valor máximo error x
%      indicadoresModelo.dymax : Valor máximo error y
%    cero: posición del cero relativo en la sala 
%          (opcional por defecto [20,5])
%    dimAbsSala: dimensiones absolutas de la sala
%                (opcional, por defecto [0 25 0 20])

%% Dibuja ensayos

% Calcula las dimensiones de la sala 
if nargin==1
    % Dimensión sala 2013 y cero ensayo experimental suministrado
    cero=[20 5];
    dimAbsSala=[0 25 0 20];
    ds=dimAbsSala-[cero(1) cero(1) cero(2) cero(2)];
elseif nargin==2
    % Dimensión sala 2013
    dimAbsSala=[0 25 0 20];
    ds=dimAbsSala-[cero(1) cero(1) cero(2) cero(2)];
else
    ds=dimAbsSala-[cero(1) cero(1) cero(2) cero(2)];
end
% Acondiciona los datos
exp=[datos.time datos.signals(1,1).values(:,1) datos.signals(1,2).values(:,1) datos.signals(1,3).values(:,1) datos.signals(1,4).values(:,1)];
modelo=[datos.time datos.signals(1,1).values(:,2) datos.signals(1,2).values(:,2) datos.signals(1,3).values(:,2) datos.signals(1,4).values(:,2)];
entrada=[datos.signals(1,5).values datos.signals(1,6).values];

% Aplica dimensiones de la sala
exp=sala(exp,ds);
modelo=sala(modelo,ds);

% Representa la respuesta
figure
subplot(6,1,1)
plot(exp(:,1),exp(:,2))
hold on,plot(modelo(:,1),modelo(:,2),'r')
title('x')
legend('Real','Modelo')
subplot(6,1,2)
plot(exp(:,1),exp(:,3))
hold on,plot(modelo(:,1),modelo(:,3),'r')
title('vx')
subplot(6,1,3)
plot(exp(:,1),exp(:,4))
hold on,plot(modelo(:,1),modelo(:,4),'r')
title('y')
subplot(6,1,4)
plot(exp(:,1),exp(:,5))
hold on,plot(modelo(:,1),modelo(:,5),'r')
title('vy')
subplot(6,1,5)
plot(exp(:,1),entrada(:,1))
title('RefPitch')
subplot(6,1,6)
plot(exp(:,1),entrada(:,2))
title('RefRoll')
xlabel('sec')

% añadida la representacion de la posicion en x e y
figure
plot(modelo(:,2),modelo(:,4))
rectangle('position',[ds(1) ds(3) ds(2)-ds(1) ds(4)-ds(3)],'LineWidth',4,'EdgeColor','r')

title('Trayectoria xy')

%% calcula indicadores 
dx=abs(exp(:,2)-modelo(:,2));
dy=abs(exp(:,4)-modelo(:,4));


indicadoresModelo.dxmedio=mean(dx);
indicadoresModelo.dymedio=mean(dy);
indicadoresModelo.dxmax=max(dx);
indicadoresModelo.dymax=max(dy);
% 
%% Dibuja Indicadores
figure
subplot(2,1,1)
plot(exp(:,1),dx,'b')
hold on,plot([exp(1,1),exp(end,1)],[indicadoresModelo.dxmax,indicadoresModelo.dxmax],'r')
hold on,plot([exp(1,1),exp(end,1)],[indicadoresModelo.dxmedio,indicadoresModelo.dxmedio],'g')
xlabel('tiempo (seg)')
ylabel('error x')
legend('error x','error max','error medio')
title(['Error x max: ' num2str(indicadoresModelo.dxmax) '; Error x medio: '  num2str(indicadoresModelo.dxmedio)])
subplot(2,1,2)
plot(exp(:,1),dy,'b')
hold on,plot([exp(1,1),exp(end,1)],[indicadoresModelo.dymax,indicadoresModelo.dymax],'r')
hold on,plot([exp(1,1),exp(end,1)],[indicadoresModelo.dymedio,indicadoresModelo.dymedio],'g')
xlabel('tiempo (seg)')
ylabel('error y')
legend('error y','error max','error medio')
title(['Error y max: ' num2str(indicadoresModelo.dymax) '; Error y medio: '  num2str(indicadoresModelo.dymedio)])


%% Registro de modificaciones:
% V.Nov_12, CPOH 2012.