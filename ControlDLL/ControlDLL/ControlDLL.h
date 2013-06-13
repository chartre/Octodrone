// DLL Template for TrackDrone Lite
// Author: Sergio Garcia-Nieto Rodriguez
// Universidad Politecnica de Valencia 2011

extern "C" {
    __declspec(dllexport) void __cdecl  Control (double *position, double *velocity, double *action, int numAxis, double *wayPointX, double *wayPointY, int numWaypoints, double *actualWayPoint, double *param, int numParam);
}
