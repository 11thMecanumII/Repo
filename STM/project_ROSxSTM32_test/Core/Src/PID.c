# include "PID.h"

const double Kp[] = {0.380348545974888, 0.398598965511759, 0.383938106220696, 0.395936692858645};
const double Ki[] = {8.64014455617426, 8.83255513394513, 8.67125871485857, 8.79655800062044};
const double Kd[] = {0.00158359752468666, 0.00182236328290195, 0.00163533883823194, 0.00179332179214608};
KPID Kpid[4] = {
    {Kp[0], Ki[0], Kd[0], 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {Kp[1], Ki[1], Kd[1], 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {Kp[2], Ki[2], Kd[2], 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {Kp[3], Ki[3], Kd[3], 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

void pidCtrl(int i){
	Kpid[i].insVel = (double) Kpid[i].enc * PI * Dwheel
			/ (4 * resolution * reduction_ratio) * frequency;
	Kpid[i].error = Kpid[i].goalVel - Kpid[i].insVel;
	Kpid[i].up = Kpid[i].Kp * Kpid[i].error;
	Kpid[i].ui += Kpid[i].Ki * Kpid[i].last_error / frequency;
	Kpid[i].ud = Kpid[i].Kd * (Kpid[i].error - Kpid[i].last_error) * frequency;
	if( fabs(Kpid[i].ui) > max_ui )
		Kpid[i].ui = (Kpid[i].ui >= 0)? max_ui: -1*max_ui;
	Kpid[i].u = Kpid[i].up + Kpid[i].ui + Kpid[i].ud;

	Kpid[i].last_error = Kpid[i].error;

	Kpid[i].pulse = fabs(Kpid[i].u) * 3200;
//	if(Kpid[i].pulse > 3200)	Kpid[i].pulse = 3200;
}
