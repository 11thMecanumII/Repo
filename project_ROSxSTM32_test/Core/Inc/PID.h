#ifndef INC_PID_H_
#define INC_PID_H_

#include <math.h>
#include <stdint.h>

#define PI 3.14159265751
#define frequency 1000
#define resolution 512
#define reduction_ratio 20.8
#define max_ui 1
#define Dwheel 0.0996		//wheelDiameter

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct{
	const double Kp;
	const double Ki;
	const double Kd;
	int16_t enc;
	double goalVel;
	double insVel;
	double error;
	double last_error;
	double u;
	double up;
	double ui;
	double ud;
	double pulse;
}KPID;

extern KPID Kpid[4];

void pidCtrl(int i);

#ifdef __cplusplus
}
#endif

#endif /* INC_PID_H_ */
