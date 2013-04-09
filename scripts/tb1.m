%% Banco de pruebas para probar distintas trayectorias de moviemiento del
% aparato.

%% Calculo de la trayectoria a seguir
% Se puede definir la distancia de los tramos y el angulo en el que se
% va a incrementar cada tramo (siempre haciendo los ejes)
dis = 10; % distancia a recorrer en cada tramo
ang = pi/12; % angulos a incrementar entre cada prueba
np = 2*pi/ang; % n de pruebas a realizar
mov = zeros (np,3); % creacion del array ruta
radio=0.1;

for i=0:np
    %% Calculo de los puntos de la ruta
    mov(i+1,1)=(i*ang)*180/pi; % angulo en grados
    mov(i+1,2)=dis*cos(i*ang); % movimiento en x
    mov(i+1,3)=dis*sin(i*ang); % movimiento en y
end
ruta = mov(:,2:3);
for i=1:(size(mov)-1)
    ruta(i+1,1:2) = ruta(i+1,1:2)+ruta(i,1:2);
end

%% Simulacion controlador de cada movimiento
    sim('simuladorControlCuatrirrotor')
    %% PDI
    pdi;
    %% Representacion grafica y calculo de indicadores
    indicadores=pintascdata(scdata,ruta,radio,scVar,pos,vE,modulo_vE,modulo_vCons,Consigna);
    
    
    %% Evaluacion
    
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
    
    Etiquetas={'Distancia Media','Distancia Maxima','Tiempo de Recorrido';
        'metros',           'metros',        'segundos'};
    
    %Evaluamos
    
    [GPP, Porcentajes, Zonas]=Rendimiento_GPP(J,PhyMatrix,Etiquetas)
    
    %% Registro de modificaciones:
    % V.Nov_12, CPOH 2012.
    