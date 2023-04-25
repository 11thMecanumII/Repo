/*
 * mainpp.h
 *
 *  Created on: 2018/01/17
 *      Author: yoneken
 */

<<<<<<< HEAD
#ifndef _MAINPP_H_
#define _MAINPP_H_
=======
#ifndef MAINPP_H_
#define MAINPP_H_
>>>>>>> origin/master

#ifdef __cplusplus
extern "C"
{
#endif
<<<<<<< HEAD
void speedsss(double* speed, double enc);
=======

>>>>>>> origin/master
void setup(void);
void loop(void);
void inter(void);

<<<<<<< HEAD
extern int run_inter0, run_inter1;
extern double Vx, Vy, W ,rVx, rVy, rW;
//extern geometry_msgs::Twist insVel;
=======
extern int run_inter;
extern double Vx, Vy, W;
>>>>>>> origin/master

#ifdef __cplusplus
}
#endif

<<<<<<< HEAD
#endif /* _MAINPP_H_ */
=======
#endif /* MAINPP_H_ */
>>>>>>> origin/master
