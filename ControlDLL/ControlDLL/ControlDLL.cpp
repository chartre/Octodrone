// DLL Template for TrackDrone Lite
// Author: Sergio Garc
// Universidad Politecnica de Valencia 2011

#include "stdafx.h"
#include "ControlDLL.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define Ts 0.06 // El TrackDroneLite va a llamar a la función "Control" cada 0.06 seg.

// Añadido nuestro (a borrar)
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>


// Estas variables son variables que van a perdurar a los ciclos

double ref_x_1;
double ref_y_1;

double e_kx = 0;
double e_kx_1 = 0;

double e_ky = 0;
double e_ky_1 = 0;

double p_x_1 = 0;
double p_y_1 = 0;

double Kcx = 0;
double Tix = 0;
double Tdx = 0;

double Kcy = 0;
double Tiy = 0;
double Tdy = 0;

int i = 1;
int contCiclo;


/* PARAMETROS
position	-> puntero a las posiciones instantaneas x y z
		x	-> position [0]
		y	-> position [1]
		z	-> position [2]

velocity	-> puntero a las velocidades instantaneas x y z
		x	-> velocity [0]
		y	-> velocity [1]
		z	-> velocity [2]

action		-> acciones a realizar sobre el aparato (RefPitch y RefRoll)
		Pitch	-> action [1]
		Roll	-> action [0]

numAxis		-> constante del numero de ejes a usar. 3 Invariables. (no útil para nosotros)

wayPointX	-> array con las componentes X de todas las posiciones del recorrido.
		wayPointX [0]	-> Corresponde a la posicion de inicio del aparato

wayPointY	-> array con las componentes Y de todas las posiciones del recorrido.
		wayPointY [0]	-> Corresponde a la posicion de inicio del aparato

numWaypoints	-> indica el numero de waypoints que hay en los vectores anteriores (el origen incluido)

actualWaypoint	-> indica al TrackDroneLite a qué waypoint estamos intentando ir

param		-> array con los parametros que le queremos dar al sistema de control (como los parametros de los pid's). En el tutorial dice que son ilimitados.

numParam	-> entero que dice cuantos elementos son los del vector anterior
*/


extern "C" {
    __declspec(dllexport) void __cdecl Control (double *position, double *velocity, double *action, int numAxis, double *wayPointX, double *wayPointY, int numWaypoints, double *actualWayPoint, double *param, int numParam)
	{
		double minT = 0;


		// Contador del numero de ciclos y del tiempo transcurrido
		double tCiclo = contCiclo*0.06;
		contCiclo++;
		 
		/* Manejo del log file*/
		char tmpbuf[10];
		_strtime_s(tmpbuf,10); // metemos en tmpbuf la hora del SO
		FILE * logfile;
		if (contCiclo == 1) // si es el primer ciclo, escribe titulo
		{
			logfile=fopen("historico.log","w");
			fprintf(logfile, "%s Tiempo\t\t(PosX    ,PosY    )\t(VelX    ,VelY    )\t(wPX     ,wPY    )\tDist\n\n",tmpbuf); // Insercion del texto
			fclose(logfile);
		}
		logfile=fopen("historico.log","a");
		fprintf(logfile, "%i\t %f\t(%f,%f)\t(%f,%f)\t(%f,%f)",(contCiclo-1),tCiclo,position[0],position[1],velocity[0],velocity[1],wayPointX[i],wayPointY[i]); // Insercion del texto
		fclose(logfile);
		
		/* Fin del logfile*/

		// Parametros del control
		// Preprocessing

		//Roll Parameters
		Kcx = 0.225;
		Tix = 0;
		Tdx = 0.667;
		actualWayPoint [0] = wayPointX[i];
		e_kx = wayPointX[i] - position[0];

		//Pitch Parameters
		Kcy = -0.2;
		Tiy = 0;
		Tdy = 1;
		actualWayPoint [1] = wayPointY[i];
		e_ky = wayPointY[i] - position[1];
		
		/* Sistema de trayectorias (aka "parte de Enrique")
		Las entradas son:
		-siguiente waypoint (wayPointX/Y[i])
		-lastRef (ref_x/y_1)
		-Ts (constante Ts)
		-radio (radio)
		Las salidas son:
		-CurrRef (ref_x/y)	*/

		int maxVx = 2;
		int maxVy = 1;
		//DistXY = SPPos-LastRef;
		double dist_x = wayPointX[i] - ref_x_1;
		double dist_y = wayPointY[i] - ref_y_1;
		//norm(DistXY)
		double normD = sqrt((dist_x*dist_x)+(dist_y*dist_y))

		if (normD<(0.5*radio))
			ref_x = wayPointX[i];
			ref_y = wayPointY[i];

		else
			minTx = abs(dist_x)/maxVx;
			minTy = abs(dist_y)/maxVy;
			// minT = max (minTx,minTy);
			if (minTx > minTy)
				minT = minTx;
			else
				minT = minTy;

			if minT<0.06
				// CurrRef = SPPos;
			ref_x = wayPointX[i];
			ref_y = wayPointY[i];

			else
				// CurrRef = LastRef + (Ts/minT)*DistXY;
				ref_x = ref_x_1 + (0.06/minT)*dist_x;
				ref_y = ref_y_1 + (0.06/minT)*dist_y;
			end
		end

		/* Corrector (aka "nuestra parte")
		Las entradas a esta seccion son:
		-posicion anterior (p_x/y_1)
		-posicion (position)
		-siguiente waypoint (wayPointX/Y[i])
		-CurrRef (ref_x/y)
		La salida es:
		-consigna (por-definir)	*/

		A=posAnt;
		B=SPPos;
		C=[posx;posy]; %construimos vector posicion

		// creamos vector director de la recta AB (recta r)
		Vr = B-A;

		// iniciamos vector Vs
		Vs = Vr;

		// creamos vector perpendicular a Vr
		Vs(1,1) = -Vr(2,1);
		Vs(2,1) = Vr(1,1);

		// creamos matriz de vectores directores
		MatrA = [Vr,-Vs];

		// creamos matriz de valores independientes
		MatrB = C-A;

		// calculamos los valores de las K's de cada recta
		K = inv(MatrA)*MatrB;

		// sacamos el punto D intereseccion de las rectas
		D = A + K(1,1)*Vr;

		vE = D-C;

		// Calculo cuando CurrRef no está sobre la trayectoria
		// Se añade esta segunda parte para corregir desviaciones de la trayectoria 
		// ideal teórica de la forma apropiada y evitar discrepancias según el método 
		// de gestión de consigna empleado. Funciona correctamente.

		// creamos matriz de valores independientes
		MatrC = CurrRef-A;

		// calculamos los valores de las K's de cada recta
		K1 = inv(MatrA)*MatrC;

		// sacamos el punto E, vertical desde CurrRef, intereseccion de las rectas
		// con trayectoria
		E = A + K1(1,1)*Vr;
		// Permite seleccionar el instante al que afecta la
		// magnitud de la corrección (posible introducción a la corrección variable
		// selectiva)
		   if norm(vE)>0.5
				   consigna = E + vE*10;
			else
				consigna = E + vE*3;


		// Fin de la parte del corrector//

		// Acciones de control
		double accion;
		// Control PID Law for X-ROLL
		// action[1] = u_kx_1 + Kcx*(e_kx - e_kx_1) + (Kcx*Ts/Tix)*e_kx + (Kcx*Tdx)/Ts*(e_kx - 2*e_kx_1 + e_kx_2);
		action[1] = Kcx*e_kx + (Kcx*Tdx)/Ts*(e_kx - e_kx_1);

		// Control PID Law for Y-PITCH
		// action[0] = action[1] + Kcy*(e_ky - e_ky_1) + (Kcy*Ts)/Tiy*e_ky + (Kcy*Tdy)/Ts*(e_ky - 2*e_ky_1 + e_ky_2);
		action[0] = Kcy*e_ky + (Kcy*Tdy)/Ts*(e_ky - e_ky_1);
		// Fin acciones de control

		// Coulombic and Viscous for X axis only
		accion = abs(action[1])+0.07;
		if (action[1] < 0)
			accion = accion *(-1);
		
		// Saturation Check
		if ((action[0]) > 0.6)
			action[0] = 0.6;

		if ((accion ) > 0.6)
			action[1] = 0.6;
		else
			action[1]=accion;

		if ((action[0]) < -0.65)
			action[0] = -0.65;

		if ((accion ) < -0.6)
			action[1] = -0.6;
		else
			action[1]=accion ;

		// Manage Variables
		e_kx_1 = e_kx;
		e_ky_1 = e_ky;

		p_x_1 = position[0];
		p_y_1 = position[1];

		double dist = sqrt((e_kx*e_kx)+(e_ky*e_ky));

		logfile=fopen("historico.log","a");
		fprintf(logfile, "\t%f\n",dist);
		fclose(logfile);
		
		if ((dist < 0.01) && (i < numWaypoints-1))
			i = i+1;
	}

}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

