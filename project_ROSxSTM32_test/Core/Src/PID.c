# include "PID.h"

const double cD[] = {0.152767, 0.152844, 0.152998, 0.154852};		//centerDistance
const double Kp[] = {1.64479466620573, 1.71135041137196, 1.70447661452659, 1.78862817629127};
const double Ki[] = {41.6708859570671, 43.3676560555242, 43.066951787975, 44.9161303770926};
const double Kd[] = {0.00746424930791678, 0.0077627606775299, 0.00777373948688634, 0.00824986692922701};
KPID Kpid[4] = {
    {Kp[0], Ki[0], Kd[0], 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, cD[0]},
    {Kp[1], Ki[1], Kd[1], 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, cD[1]},
    {Kp[2], Ki[2], Kd[2], 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, cD[2]},
    {Kp[3], Ki[3], Kd[3], 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, cD[3]}
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

	Kpid[i].pulse = fabs(Kpid[i].u) * PWM_ARR;
	if(Kpid[i].pulse > PWM_ARR)	Kpid[i].pulse = PWM_ARR;
}
