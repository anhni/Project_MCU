/*
 * global.h
 *
 *  Created on: Sep 30, 2022
 *      Author: anhni
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define MODE_INIT 0
#define MODE_1 1
#define MODE_2 2
#define MODE_3 3
#define MODE_4 4

#define MODE_LED_INIT 0
#define MODE_LED_1 1
#define MODE_LED_2 2
#define MODE_LED_3 3

extern int mode;
extern int mode_led1;
extern int mode_led2;

extern int led_red;
extern int led_green;
extern int led_yellow;

extern int counter;

extern int TIMER_CYCLE;

extern char buffer[10];

extern int time_flag;
extern int buzz_flag;
extern int walk_flag;

#endif /* INC_GLOBAL_H_ */
