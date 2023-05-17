#include "odometry.h"

ODOM odom;

void odom_update(double Vx_world, double Vy_world, double W){
    odom.x += (double)Vx_world / frequency;
    odom.y += (double)Vy_world / frequency;
    odom.theta += (double)W / frequency;
    while(odom.theta > PI)  odom.theta -= 2*PI;
    while(odom.theta < -1*PI) odom.theta += 2*PI;
    return;
}
double vel_World2Car(char coor, double Vx_world, double Vy_world){
	double coff = 1/ cos(2 * odom.theta);
	if(coor == 'x')
		return coff * (Vy_world * cos(odom.theta) - Vx_world * sin(odom.theta));
	else
		return coff * (Vx_world * cos(odom.theta) - Vy_world * sin(odom.theta));

}
double vel_Car2World(char coor, double Vx, double Vy){
	if(coor == 'x')
		return Vx * sin( odom.theta ) + Vy * cos( odom.theta );
	else
		return Vx * cos( odom.theta ) + Vy * sin( odom.theta );
}

