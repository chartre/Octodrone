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


// Estas variables van a perdurar a los ciclos
double A[2];
double B[2];
double C[2];
double Vr[2];
double Vs[2];
double D[2];
double vE[2];
double E[2];
double consigna[2];
double MatrA [2][2];
double MatrAt [2][2];
double MatrB [2];
double MatrK [2];
double MatrC [2];
double MatrK1 [2];

double minT;
double radio = 0.1;

double minTx;
double minTy;

double ref_x;
double ref_y;
double ref_x_1;
double ref_y_1;

double d_wx;
double e_kx = 0;
double e_kx_1 = 0;
double e_kx_2 = 0;

double d_wy;
double e_ky = 0;
double e_ky_1 = 0;
double e_ky_2 = 0;

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

// Funciones adicionales
double norm (double a, double b)
{
	return sqrt((a*a+b*b));
}
double sat (double valor, double top, double bottom)
{
	if (valor > top)
	{
		return top;
	}else if (valor < bottom)
	{
		return bottom;
	}
	else
	{
		return valor;
	}
}

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
			logfile=fopen("salidaPIDs.log","w");
			fprintf(logfile, "%s Tiempo\t\t(PosX    ,PosY    )\t(VelX    ,VelY    )\t(wPX     ,wPY    )\tDist\t\tConsigna\t\tWPAnterior\n\n",tmpbuf); // Insercion del texto
			fclose(logfile);
		}
		logfile=fopen("historico.log","a");
		fprintf(logfile, "%i\t %f\t(%f,%f)\t(%f,%f)\t(%f,%f)",(contCiclo-1),tCiclo,position[0],position[1],velocity[0],velocity[1],wayPointX[i],wayPointY[i]); // Insercion del texto
		fclose(logfile);
		
		/* Fin del logfile*/

		// Parametros del control
		// Preprocessing

		//Roll Parameters
		actualWayPoint [0] = wayPointX[i];
		d_wx = wayPointX[i] - position[0];

		//Pitch Parameters
		actualWayPoint [1] = wayPointY[i];
		d_wy = wayPointY[i] - position[1];
		
		///* Sistema de trayectorias (aka "parte de Enrique")
		//===================================================
		//Las entradas son:
		//-siguiente waypoint (wayPointX/Y[i])
		//-lastRef (ref_x/y_1)
		//-Ts (constante Ts)
		//-radio (radio)
		//Las salidas son:
		//-CurrRef (ref_x/y)	*/

		int maxVx = 2;
		int maxVy = 1;
		//DistXY = SPPos-LastRef;
		double dist_x = wayPointX[i] - ref_x_1;
		double dist_y = wayPointY[i] - ref_y_1;
		//norm(DistXY)
		double normD = norm (dist_x,dist_y);

		if (normD < (0.5*radio))
		{
			ref_x = wayPointX[i];
			ref_y = wayPointY[i];
		}
		else
		{
			minTx = abs(dist_x)/maxVx;
			minTy = abs(dist_y)/maxVy;
			// minT = max (minTx,minTy);
			if (minTx > minTy)
			{
				minT = minTx;
			}
			else
			{
				minT = minTy;
			}

			if (minT < 0.06)
			{
				// CurrRef = SPPos;
				ref_x = wayPointX[i];
				ref_y = wayPointY[i];
			}
			else
			{
				// CurrRef = LastRef + (Ts/minT)*DistXY;
				ref_x = ref_x_1 + (0.06/minT)*dist_x;
				ref_y = ref_y_1 + (0.06/minT)*dist_y;
			}
		}

		///* Corrector (aka "nuestra parte")
		//==================================
		//Las entradas a esta seccion son:
		//-posicion anterior (p_x/y_1)
		//-posicion (position)
		//-siguiente waypoint (wayPointX/Y[i])
		//-CurrRef (ref_x/y)
		//La salida es:
		//-consigna (por-definir)	*/

		//A[0] = wayPointX[i-1];
		//A[1] = wayPointX[i-1];

		//B[0] = wayPointX[i];
		//B[1] = wayPointY[i];

		////construimos vector posicion
		//C[0] = position[0];
		//C[1] = position[1];

		//// creamos vector director de la recta AB (recta r)
		//Vr[0] = B[0]-A[0];
		//Vr[1] = B[1]-A[1];

		//// iniciamos vector Vs
		//// (no necesario en c++)

		//// creamos vector perpendicular a Vr
		//Vs[0] = -Vr[1];
		//Vs[1] = Vr[0];

		//// creamos matriz de vectores directores
		//MatrA[0][0] = Vr[0];
		//MatrA[0][1] = -Vs[0];
		//MatrA[1][0] = Vr[1];
		//MatrA[1][1] = -Vs[1];

		//// creamos matriz de valores independientes
		//MatrB[0] = C[0]-A[0];
		//MatrB[1] = C[1]-A[1];

		//// calculamos los valores de las K's de cada recta

		//// Inversa de MatrA
		//double detA = (MatrA[0][0]*MatrA[1][1]) - (MatrA[0][1]*MatrA[1][0]);
		//MatrAt[0][0]=MatrA[1][1];
		//MatrAt[0][1]=-MatrA[0][1];
		//MatrAt[1][0]=-MatrA[1][0];
		//MatrAt[1][1]=MatrA[0][0];

		//MatrAt[0][0]=MatrAt[0][0]/detA;
		//MatrAt[0][1]=MatrAt[0][1]/detA;
		//MatrAt[1][0]=MatrAt[1][0]/detA;
		//MatrAt[1][1]=MatrAt[1][1]/detA;

		//// Matriz de valores k
		//MatrK[0]=(MatrAt[0][0]*MatrB[0]) + (MatrA[0][1]*MatrB[1]);
		//MatrK[1]=(MatrAt[1][0]*MatrB[0]) + (MatrA[1][1]*MatrB[1]);

		//// sacamos el punto D intereseccion de las rectas
		//// D = A + K(1,1)*Vr;
		//D[0]=A[0]+MatrK[0]*Vr[0];
		//D[1]=A[1]+MatrK[0]*Vr[1];

		//vE[0] = D[0]-C[0];
		//vE[1] = D[1]-C[1];

		//// Calculo cuando CurrRef no está sobre la trayectoria
		//// Se añade esta segunda parte para corregir desviaciones de la trayectoria 
		//// ideal teórica de la forma apropiada y evitar discrepancias según el método 
		//// de gestión de consigna empleado. Funciona correctamente.

		//// creamos matriz de valores independientes
		//MatrC[0] = ref_x - A[0];
		//MatrC[1] = ref_y - A[1];

		//// calculamos los valores de las K's de cada recta
		//// K1 = inv(MatrA)*MatrC;
		//MatrK1[0]=(MatrAt[0][0]*MatrC[0]) + (MatrAt[0][1]*MatrC[1]);
		//MatrK1[1]=(MatrAt[1][0]*MatrC[0]) + (MatrAt[1][1]*MatrC[1]);

		//// sacamos el punto E, vertical desde CurrRef, intereseccion de las rectas
		//// con trayectoria
		//// E = A + K1(1,1)*Vr;
		//E[0]=A[0]+MatrK1[0]*Vr[0];
		//E[1]=A[1]+MatrK1[0]*Vr[1];

		//// Permite seleccionar el instante al que afecta la
		//// magnitud de la corrección (posible introducción a la corrección variable
		//// selectiva)
		//double normvE = sqrt((vE[0]*vE[0]) + (vE[1]*vE[1]));

		//if (normvE > 0.5)
		//{
		//	consigna[0] = E[0] + vE[0]*10;
		//	consigna[1] = E[1] + vE[1]*10;
		//}
		//else
		//{
		//	consigna[0] = E[0] + vE[0]*3;
		//	consigna[1] = E[1] + vE[1]*3;
		//}
		//// Fin de la parte del corrector//

		//consigna[0] = wayPointX[i];
		//consigna[1] = wayPointY[i];
		
		e_kx = ref_x - position[0];
		e_ky = ref_y - position[1];

		// Acciones de control
		double accion;
		// Control PID Law for X-ROLL
		// action[1] = u_kx_1 + Kcx*(e_kx - e_kx_1) + (Kcx*Ts/Tix)*e_kx + (Kcx*Tdx)/Ts*(e_kx - 2*e_kx_1 + e_kx_2);
		// action[1] = Kcx*e_kx + (Kcx*Tdx)/Ts*(e_kx - e_kx_1);
		//Pitch Parameters
		Kcx = 1;
		Tix = 0;
		Tdx = 0;
		int Nx = 12;
		action[1] = Kcx*e_kx; //+ (Kcx*Tdx)*Nx*(e_kx - 2*e_kx_1 + e_kx_2)/((e_kx - 2*e_kx_1 + e_kx_2) + Nx*Ts);

		// Control PID Law for Y-PITCH
		// action[0] = action[1] + Kcy*(e_ky - e_ky_1) + (Kcy*Ts)/Tiy*e_ky + (Kcy*Tdy)/Ts*(e_ky - 2*e_ky_1 + e_ky_2);
		// Roll Params
		Kcy = 1.5;
		Tiy = 0;
		Tdy = 3;
		int Ny = 20;
		action[0] =-( Kcy*e_ky + (Kcy*Tdy)*Ny*(e_ky - 2*e_ky_1 + e_ky_2)/((e_ky - 2*e_ky_1 + e_ky_2) + Ny*Ts));

		// action[0] = Kcy*e_ky + (Kcy*Tdy)/Ts*(e_ky - e_ky_1);
		// Fin acciones de control

		// Coulombic and Viscous for X axis only
		//accion = (abs(action[1]))+0.07;
		//if (action[1] < 0)
		//	accion = accion *(-1);

		// Saturation Check
		action[0] = sat(action[0],0.6,-0.65);
		action[1] = sat(action[1],0.6,-0.6);

		// Manage Variables
		e_kx_2 = e_kx_1;
		e_ky_2 = e_ky_1;
		e_kx_1 = e_kx;
		e_ky_1 = e_ky;
		ref_x_1 = ref_x;
		ref_y_1 = ref_y;

		double dist = norm(d_wx,d_wy);

		logfile=fopen("historico.log","a");
		fprintf(logfile, "\t%f\t(%f,%f)\t(%f,%f|%f,%f)\n",dist,consigna[0],consigna[1],wayPointX[i],wayPointY[i],wayPointX[i-1],wayPointY[i-1]);
		fclose(logfile);
		
		if ((dist < 0.01) && (i < numWaypoints-1))
			i = i+1;

		/* Manejo del archivo log de las salidas de los PIDs)*/
		logfile=fopen("salidaPIDs.log","a");
		fprintf(logfile, "%f\t%f\n",action[0]); // Insercion del texto
		fclose(logfile);

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