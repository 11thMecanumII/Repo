/*
 * PID.h
 *
 *  Created on: 2023年4月27日
 *      Author: chenw
 */

#ifndef INC_PID_H_
#define INC_PID_H_

# include <string.h>

typedef struct{
	const double Kp;
	const double Ki;
	const double Kd;
	double error;
	double u;
	double up;
	double ui;
	double ud;
}KPID;

extern KPID Kpid[4];

void pidCtrl(int i, double goalVel, double insVel);

#endif /* INC_PID_H_ */
