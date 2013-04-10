%% Banco de pruebas para probar distintas trayectorias de moviemiento del
% aparato.

%% Calculo de la trayectoria a seguir
% Se puede definir la distancia de los tramos y el angulo en el que se
% va a incrementar cada tramo (siempre haciendo los ejes)
dis = 10; % distancia a recorrer en cada tramo
ang = pi/6; % angulos a incrementar entre cada prueba
np = floor(2*pi/ang); % n de pruebas a realizar
mov = zeros (np,3); % creacion del array de tramos
output = cell(np+1,5);
radio=0.1;

%% Calculo de los trayectos de la ruta
for i=1:np
    mov(i,1)=((i-1)*ang)*180/pi; % angulo en grados
    mov(i,2)=dis*cos((i-1)*ang); % movimiento en x
    mov(i,3)=dis*sin((i-1)*ang); % movimiento en y
end
rutaEntera = mov(:,2:3);

%% Calculo de los puntos de la ruta
% for i=1:(size(mov)-1)
%     rutaEntera(i+1,1:2) = rutaEntera(i+1,1:2)+rutaEntera(i,1:2);
% end

%% Simulacion por partes
ruta = zeros(2,2);
    figure
    hold on

for i=1:np
    ruta = rutaEntera(i,1:2);
    ruta(2,:) = ruta(1,:); % insertamos dos veces el mismo punto para que no deproblemas el simulink
    
    %% Simulacion controlador de cada movimiento
    simtime = size(ruta,1)*10; % le damos un tiempo de ejecucion de 10 segundos por cada trayecto
    sim('simuladorControlCuatrirrotor')

    %% Representacion grafica y calculo de indicadores
    indicadores=pintascdata_tb2(scdata,ruta,radio,scVar,pos,vE,modulo_vE,modulo_vCons);
    
    %% Evaluacion
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
    
    % Evaluamos
    [GPP, Porcentajes, Zonas]=Rendimiento_GPP_tb2(J,PhyMatrix);
    
    % Recogemos datos
    output(i+1,3:5) = Zonas;
    output{i+1,2} = GPP;
    output{i+1,1} = i;
end
%% Muestra los dtos obtenidos
output{1,1}='N';
output{1,2}='GPP';
output{1,3}='D med';
output{1,4}='D Max';
output{1,5}='Time';
disp(output)