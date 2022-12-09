/*
 * display.h
 *
 *  Created on: Nov 4, 2022
 *      Author: anhni
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "global.h"
#include "software_timer.h"
#include "button.h"
void fsm_simple_buttons_run ();
void fsm_led1_run();
void fsm_led2_run();
void update7SEG(int index);
void led_blinky ();

#endif /* INC_DISPLAY_H_ */
