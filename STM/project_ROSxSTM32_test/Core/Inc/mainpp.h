#ifndef _MAINPP_H_
#define _MAINPP_H_

#ifdef __cplusplus
extern "C"
{
#endif

extern int run_inter0, run_inter1;
extern double Vx, Vy, W ,rVx, rVy, rW;

void interPub(void);
void setup(void);
void loop(void);

#ifdef __cplusplus
}
#endif


#endif /* _MAINPP_H_ */
