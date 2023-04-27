# include "PID.h"

KPID Kpid[4];

void pidCtrl(int i, double goalVel, double insVel){
	Kpid[i].error = goalVel - insVel;
//	Kpid[i].up = Kpid[i].Kp *　Kpid[i].error;

//	it[i] = et[i];
//	PV[i] = (double) enc[i] * PI * 0.0996 / (4 * resolution * reduction_ratio) * frequency;
//	et[i] = SV[i] - PV[i];
//	up[i] = Kp[i] * et[i];
//	ui[i] += Ki[i] * it[i] * 0.001;
//	ud[i] = Kd[i] * (et[i] - it[i]) / 0.001;
//	if (ui[i] > imax)ui[i] = imax;
//	else if (ui[i] < imax * -1)ui[i] = imax * -1;
//	ut[i] = up[i] + ui[i] + ud[i];
//	ut[i] > 0 ? (pulse[i] = ut[i] * 3200) : (pulse[i] = ut[i] * -3200);
//	if(pulse[i] > 3200) pulse[i] = 3200;

}
