// DLL Template for TrackDrone Lite
// Author: Sergio Garc
// Universidad Politecnica de Valencia 2011

#include "stdafx.h"
#include "ControlDLL.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define Ts 0.06 // El TrackDroneLite va a llamar a la función "Control" cada 0.06 seg.

// Para crear el log
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


// Estas variables son variables que van a perdurar a los ciclos

double e_kx = 0;
double e_kx_1 = 0;

double e_ky = 0;
double e_ky_1 = 0;

double Kcx = 0;
double Tix = 0;
double Tdx = 0;

double Kcy = 0;
double Tiy = 0;
double Tdy = 0;

int i = 1;
double pos[3];
double *wPx;
double *wPy;


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

numWaypoints	-> indica el numero de waypoints que hay en los vectores anteriores (suponemos que el origen incluido)

actualWaypoint	-> indica al TrackDroneLite a qué waypoint estamos intentando ir

param		-> array con los parametros que le queremos dar al sistema de control (como los parametros de los pid's). En el tutorial dice que son ilimitados.

numParam	-> entero que dice cuantos elementos son los del vector anterior
*/


extern "C" {
    __declspec(dllexport) void __cdecl Control (double *position, double *velocity, double *action, int numAxis, double *wayPointX, double *wayPointY, int numWaypoints, double *actualWayPoint, double *param, int numParam)
	{
		// creamos variables locales para poder verlas en el debugger
		pos[0] = position[0];
		pos[1] = position[1];

		wPx = new double[numWaypoints];
		wPy = new double[numWaypoints];
		
		for(int i=0;i<numWaypoints;i++){
			wPx[i] = wayPointX[i];
			wPy[i] = wayPointY[i];
		}


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

		// Control PID Law for X-ROLL
		//action[1] = u_kx_1 + Kcx*(e_kx - e_kx_1) + (Kcx*Ts/Tix)*e_kx + (Kcx*Tdx)/Ts*(e_kx - 2*e_kx_1 + e_kx_2);
		action[1] = Kcx*e_kx + (Kcx*Tdx)/Ts*(e_kx - e_kx_1);

		// Control PID Law for Y-PITCH
		//action[0] = action[1] + Kcy*(e_ky - e_ky_1) + (Kcy*Ts)/Tiy*e_ky + (Kcy*Tdy)/Ts*(e_ky - 2*e_ky_1 + e_ky_2);
		action[0] = Kcy*e_ky + (Kcy*Tdy)/Ts*(e_ky - e_ky_1);

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
		e_kx_1 = e_kx;
		e_ky_1 = e_ky;

		if ((abs(e_kx) < 0.01) && (abs(e_ky) < 0.01) && (i < numWaypoints-1))// cambiar esto a detectar dentro del radio y no cuando los dos errores sean nulos
			i = i+1;

		printf("3");

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

