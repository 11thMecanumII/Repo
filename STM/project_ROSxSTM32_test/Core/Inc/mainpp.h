/*
 * mainpp.h
 *
 *  Created on: 2018/01/17
 *      Author: yoneken
 */

#ifndef _MAINPP_H_
#define _MAINPP_H_

#ifdef __cplusplus
extern "C"
{
#endif
void speedsss(double* speed, double enc);
void setup(void);
void loop(void);
void inter(void);

extern int run_inter0, run_inter1;
extern double Vx, Vy, W ,rVx, rVy, rW;
//extern geometry_msgs::Twist insVel;

#ifdef __cplusplus
}
#endif

#endif /* _MAINPP_H_ */
