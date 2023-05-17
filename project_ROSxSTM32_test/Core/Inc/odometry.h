#ifndef _ODOMETRY_H_
#define _ODOMETRY_H_

#include "mainpp.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define PI 3.14159265751
#define dt 0.001

typedef struct{
    double x;
    double y;
    double theta;
}ODOM;

extern ODOM odom;

void odom_update(double Vx_world, double Vy_world, double W);
double vel_Car2World(char coor, double Vx, double Vy);
double vel_World2Car(char coor, double Vx_world, double Vy_world);

#ifdef __cplusplus
}
#endif

#endif
