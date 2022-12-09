#ifndef __SOFTWARE_TIMER_
#define __SOFTWARE_TIMER_

extern int timer0_flag;
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);

void timerRun();
void clearTimer1();
#endif
