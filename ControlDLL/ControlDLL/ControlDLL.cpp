// DLL Template for TrackDrone Lite
// Author: Sergio Garc
// Universidad Politecnica de Valencia 2011

#include "stdafx.h"
#include "ControlDLL.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define Ts 0.06

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

int i;

extern "C" {
    __declspec(dllexport) void __cdecl Control (double *position, double *velocity, double *action, int numAxis, double *wayPointX, double *wayPointY, int numWaypoints, double *actualWayPoint, double *param, int numParam)
	{

		
		// Preprocessing
		//Roll Parameters
		Kcx = param[0];
		Tix = param[1];
		Tdx = param[2];
		e_kx = wayPointX[i] - position[0];
		
		//Pitch Parameters
		Kcy = param[3];
		Tiy = param[4];
		Tdy = param[5];
		e_ky = wayPointY[i] - position[1];

		if((e_kx+e_ky)<0.1)
			i++;

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

