// DLL Template for TrackDrone Lite

#include "stdafx.h"
#include "ControlDLL.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Ts 0.06 // El TrackDroneLite va a llamar a la función "Control" cada 0.06 seg.

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
		actualWayPoint[2]=i;

		// Parametros del control
		// Preprocessing

		//Roll Parameters
		actualWayPoint [0] = wayPointX[i];
		d_wx = wayPointX[i] - position[0];

		//Pitch Parameters
		actualWayPoint [1] = wayPointY[i];
		d_wy = wayPointY[i] - (position[1]); // Cambiamos signos en valor posición para eje Y por entender convenio de signos a la inversa. También se modifica en otro uso de esta variable más adelante del código.
		
		///* Sistema de trayectorias
		//===================================================
		//Las entradas son:
		//-siguiente waypoint (wayPointX/Y[i])
		//-lastRef (ref_x/y_1)
		//-Ts (constante Ts)
		//-radio (radio)
		//Las salidas son:
		//-CurrRef (ref_x/y)	*/

		int maxVx = 1;
		int maxVy = 2;
		//DistXY = SPPos-LastRef;
		double dist_x = wayPointX[i] - ref_x_1;
		double dist_y = wayPointY[i] - ref_y_1;
		//norm(DistXY)
		// double normD = norm (dist_x,dist_y);
		double normD = sqrt( (dist_x *dist_x) + (dist_y *dist_y) );

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

		///* Corrector
		//==================================
		//Las entradas a esta seccion son:
		//-posicion anterior (p_x/y_1)
		//-posicion (position)
		//-siguiente waypoint (wayPointX/Y[i])
		//-CurrRef (ref_x/y)
		//La salida es:
		//-consigna (por-definir)	*/

		A[0] = wayPointX[i-1];
		A[1] = wayPointY[i-1];

		B[0] = wayPointX[i];
		B[1] = wayPointY[i];

		//construimos vector posicion
		C[0] = position[0];
		C[1] = position[1];

		// creamos vector director de la recta AB (recta r)
		Vr[0] = B[0]-A[0];
		Vr[1] = B[1]-A[1];

		// iniciamos vector Vs
		// (no necesario en c++)

		// creamos vector perpendicular a Vr
		Vs[0] = -Vr[1];
		Vs[1] = Vr[0];

		// creamos matriz de vectores directores
		MatrA[0][0] = Vr[0];
		MatrA[0][1] = -Vs[0];
		MatrA[1][0] = Vr[1];
		MatrA[1][1] = -Vs[1];

		// creamos matriz de valores independientes
		MatrB[0] = C[0]-A[0];
		MatrB[1] = C[1]-A[1];

		// calculamos los valores de las K's de cada recta

		// Inversa de MatrA
		double detA = (MatrA[0][0]*MatrA[1][1]) - (MatrA[0][1]*MatrA[1][0]);
		MatrAt[0][0]=MatrA[1][1];
		MatrAt[0][1]=-MatrA[0][1];
		MatrAt[1][0]=-MatrA[1][0];
		MatrAt[1][1]=MatrA[0][0];

		MatrAt[0][0]=MatrAt[0][0]/detA;
		MatrAt[0][1]=MatrAt[0][1]/detA;
		MatrAt[1][0]=MatrAt[1][0]/detA;
		MatrAt[1][1]=MatrAt[1][1]/detA;

		// Matriz de valores k
		MatrK[0]=(MatrAt[0][0]*MatrB[0]) + (MatrA[0][1]*MatrB[1]);
		MatrK[1]=(MatrAt[1][0]*MatrB[0]) + (MatrA[1][1]*MatrB[1]);

		// sacamos el punto D intereseccion de las rectas
		// D = A + K(1,1)*Vr;
		D[0]=A[0]+MatrK[0]*Vr[0];
		D[1]=A[1]+MatrK[0]*Vr[1];

		vE[0] = D[0]-C[0];
		vE[1] = D[1]-C[1];

		// Calculo cuando CurrRef no está sobre la trayectoria
		// Se añade esta segunda parte para corregir desviaciones de la trayectoria 
		// ideal teórica de la forma apropiada y evitar discrepancias según el método 
		// de gestión de consigna empleado. Funciona correctamente.

		// creamos matriz de valores independientes
		MatrC[0] = ref_x - A[0];
		MatrC[1] = ref_y - A[1];

		// calculamos los valores de las K's de cada recta
		// K1 = inv(MatrA)*MatrC;
		MatrK1[0]=(MatrAt[0][0]*MatrC[0]) + (MatrAt[0][1]*MatrC[1]);
		MatrK1[1]=(MatrAt[1][0]*MatrC[0]) + (MatrAt[1][1]*MatrC[1]);

		// sacamos el punto E, vertical desde CurrRef, intereseccion de las rectas
		// con trayectoria
		// E = A + K1(1,1)*Vr;
		E[0]=A[0]+MatrK1[0]*Vr[0];
		E[1]=A[1]+MatrK1[0]*Vr[1];

		// Permite seleccionar el instante al que afecta la
		// magnitud de la corrección (posible introducción a la corrección variable
		// selectiva)
		double normvE = sqrt((vE[0]*vE[0]) + (vE[1]*vE[1]));

		if (normvE > 10.5)
		{
			consigna[0] = E[0] + vE[0]*10;
			consigna[1] = E[1] + vE[1]*10;
		}
		else
		{
			consigna[0] = E[0] + vE[0]*0.005;
			consigna[1] = E[1] + vE[1]*0.005;
		}
		// Fin de la parte del corrector//

		ref_x=consigna[0];
		ref_y=consigna[1];

		e_kx = ref_x - position[0];
		e_ky = ref_y - (position[1]);

		// Acciones de control
		// Control PID Law for X-PITCH
		// Pitch Param¡eters
		/*Kcx = 0.1;
		Tix = 0;
		Tdx = 0.05;
		int Nx = 12;*/
		Kcx = 1.5;
		Tix = 0;
		Tdx = 3;
		int Nx = 20;
		action[1] = (Kcx*e_kx + ((Tdx*Nx)/(1+(Nx*Ts/(e_kx_1 - e_kx_2)))));
		// Anulamos "action[]" de este eje para medir sólo el otro.

		// Control PID Law for Y-ROLL
		// Roll Params
		/*Kcy = 1.5;
		Tiy = 0;
		Tdy = 3;
		int Ny = 20;*/
		Kcy = 0.1;
		Tiy = 0;
		Tdy = 0.05;
		int Ny = 12;
		action[0] = -(Kcy*e_ky + ((Tdy*Ny)/(1+(Ny*Ts/(e_ky_1 - e_ky_2)))));

		// Fin acciones de control


		// Coulombic and Viscous for X axis only????????????????????????????????????????????????????????????????????????????
		 double accion;
		 accion = (abs(action[1]))+0.07;
		 if (action[1] < 0)
			accion = accion *(-1);

		// Saturation Check
		// FUNCION: action[0] = sat(action[0],0.6,-0.6);
		double valor = action[0];
		double top = 0.1; //0.6
		double bottom = -0.1; //0.65

		if (valor > top){
			action[0] = top;
		}else if (valor < bottom){
			action[0] = bottom;
		}

		// FUNCION action[1] = sat(action[1],0.6,-0.65);
		valor = action[1];
		top = 0.1; //0.6
		bottom = -0.1; //-0.6

		if (valor > top)
		{
			action[1] = top;
		}else if (valor < bottom)
		{
			action[1] = bottom;
		}
		
		// Manage Variables
		e_kx_2 = e_kx_1;
		e_ky_2 = e_ky_1;
		e_kx_1 = e_kx;
		e_ky_1 = e_ky;
		ref_x_1 = ref_x;
		ref_y_1 = ref_y;

		// double dist = norm(d_wx,d_wy);
		double dist = sqrt((d_wx*d_wx)+(d_wy*d_wy));

		if ((dist < 0.1) && (i < numWaypoints-1))
			i++;

		//actualWayPoint[2]=i;
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