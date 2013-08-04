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

double U_x = 0;
double e_kx = 0;
double e_kx_1 = 0;
double e_kx_2 = 0;

double U_y = 0;
double e_ky = 0;
double e_ky_1 = 0;
double e_ky_2 = 0;

double Kcx = 0;
double Tix = 0;
double Tdx = 0;
double Nx = 0;

double Kcy = 0;
double Tiy = 0;
double Tdy = 0;
double Ny = 0;

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
		Pitch	-> action [0]
		Roll	-> action [1]

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
		Kcx = 0.1;
		Tix = 0;
		Tdx = 0.05;
		Nx = 12;
		actualWayPoint [0] = wayPointX[i];
		e_kx = wayPointX[i] - position[0];

		//Pitch Parameters
		Kcy = 1.5;
		Tiy = 0;
		Tdy = 3;
		Ny = 20;
		actualWayPoint [1] = wayPointY[i];
		e_ky = wayPointY[i] - position[1];

		// Control PID Law for X-ROLL
		//action[1] = u_kx_1 + Kcx*(e_kx - e_kx_1) + (Kcx*Ts/Tix)*e_kx + (Kcx*Tdx)/Ts*(e_kx - 2*e_kx_1 + e_kx_2);
		action[1] = Kcx*e_kx + (Kcx*Tdx)*Nx*(e_kx - 2*e_kx_1 + e_kx_2)/((e_kx - 2*e_kx_1 + e_kx_2) + Nx*Ts); // Obteneos la configuración de la fórmula de la ayuda de Simulink para definir el PID

		// Control PID Law for Y-PITCH
		//action[0] = action[1] + Kcy*(e_ky - e_ky_1) + (Kcy*Ts)/Tiy*e_ky + (Kcy*Tdy)/Ts*(e_ky - 2*e_ky_1 + e_ky_2);
		// action[0] = (Kcy*e_ky + (Kcy*Tdy)*Ny*(e_ky - 2*e_ky_1 + e_ky_2)/((e_ky - 2*e_ky_1 + e_ky_2) + Ny*Ts))*-1; // La dirección parece estar invertida respecto a nuestro modelo, en el que invierte el eje X
		action[0] = Kcy*e_ky + (Kcy*Tdy)/Ts*(e_ky - e_ky_1); // Propuesta ejemplo del documento original

		// Saturation Check
		if ((action[0]) > 1)
			action[0] = 1;

		if ((action[1]) > 1)
			action[1] = 1;

		if ((action[0]) < -1)
			action[0] = -1;

		if ((action[1]) < -1)
			action[1] = -1;

		// Manage Variables
		e_kx_2 = e_kx_1;
		e_kx_1 = e_kx;
		// U_x = action[1];
		e_ky_2 = e_ky_1;
		e_ky_1 = e_ky;
		// U_y = action[0];
		
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

