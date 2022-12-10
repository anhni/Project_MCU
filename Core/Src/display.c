/*
 * display.c
 *
 *  Created on: Nov 4, 2022
 *      Author: anhni
 */

#include "display.h"
#include "software_timer.h"
#include "button.h"
#include "main.h"


void fsm_simple_buttons_run () {
	switch(mode){
		case MODE_INIT:
			setTimer0(1000);
			mode = MODE_1;
		break;
		case MODE_1:
			fsm_led1_run();
			fsm_led2_run();
			if(timer0_flag == 1){
				if(counter > 0){
					counter--;
				}
				//print time();
				time_flag = 1;
				setTimer0(1000);
			}
			if(is_Button1_Pressed()){
				walk_flag = 0;
				buzz_flag = 0;
				setTimer0(10000);
				setTimer3(1000);
				mode = 2;
			}
//			if(is_Button2_Pressed()){
//				setTimer0(10000);
//				mode = 2;
//			}
//			if(is_Button3_Pressed()){
//				setTimer0(10000);
//				mode = 2;
//			}
			if(is_Button4_Pressed()){
				//time for walking
				setTimer4(1000);
				buzz_flag = 1;
				setTimer3(10000);
				walk_flag = 1;
			}
			if(timer3_flag == 1){
				walk_flag = 0;
				buzz_flag = 0;
			}
		break;
		case MODE_2:
			//setting led red time
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
			//counter
			if(timer3_flag == 1){
				time_flag = 1;
				setTimer3(1000);
			}

			if(is_Button1_Pressed()){
//				counter = 0;
				mode = MODE_3;
				setTimer0(10000);
			}

			if(is_Button1_Pressed_3s()){
			//	counter = 0;
				mode = MODE_INIT;
			}
			if(is_Button2_Pressed()){
				led_red++;
				if(led_red > 99) led_red = 0;
				setTimer0(10000);
			}
			if(is_Button3_Pressed()){
				led_red--;
				if(led_red < 0) led_red = 99;
				setTimer0(10000);
			}
			if(timer0_flag == 1){
				mode = MODE_INIT;
			}
		break;
		case MODE_3:
			//setting led green time
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
			//counter
			if(timer3_flag == 1){
				time_flag = 1;
				setTimer3(1000);
			}
			if(is_Button1_Pressed()){
//				counter = 0;
				mode = MODE_4;
				setTimer0(10000);
			}

			if(is_Button1_Pressed_3s()){
			//	counter = 0;
				mode = MODE_INIT;
			}
			if(is_Button2_Pressed()){
				led_green++;
				if(led_green > 99) led_green = 0;
				setTimer0(10000);
			}
			if(is_Button3_Pressed()){
				led_green--;
				if(led_green < 0) led_green = 99;
				setTimer0(10000);
			}
			if(timer0_flag == 1){
				mode = MODE_INIT;
			}
		break;
		case MODE_4:
			//setting led yellow time
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
			//counter
			if(timer3_flag == 1){
				time_flag = 1;
				setTimer3(1000);
			}
			if(is_Button1_Pressed()){
//				counter = 0;
				mode = MODE_INIT;
				setTimer0(10000);
			}
			if(is_Button1_Pressed_3s()){
				//	counter = 0;
				mode = MODE_INIT;
			}
			if(is_Button2_Pressed()){
				led_yellow++;
				if(led_yellow > 99) led_yellow = 0;
				setTimer0(10000);
			}
			if(is_Button3_Pressed()){
				led_yellow--;
				if(led_yellow < 0) led_yellow = 99;
				setTimer0(10000);
			}
			if(timer0_flag == 1){
				mode = MODE_INIT;
			}
			break;
	}
}
void fsm_led1_run(){
	switch(mode_led1){
		case MODE_LED_INIT:
			setTimer1(led_red*1000);
			counter = led_red;
			mode_led1 = MODE_LED_1;
		break;
		case MODE_LED_1://red
		HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
		if (walk_flag == 1){
			//green
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
			HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
		}
		if(timer1_flag == 1){
			mode_led1 = MODE_LED_2;
			counter = led_green;
			setTimer1(led_green*1000);
		}
		break;
		case MODE_LED_2://green
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
			if (walk_flag == 1){
				//red
				HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
				HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
			}
			if(timer1_flag == 1){
				mode_led1 = MODE_LED_3;
				counter = led_yellow;
				setTimer1(led_yellow*1000);
			}
		break;
		case MODE_LED_3://yellow
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
			if (walk_flag == 1){
				//green
				HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
				HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
			}
			if(timer1_flag == 1){
				mode_led1 = MODE_LED_1;
				counter = led_red;
				setTimer1(led_red*1000);
			}
		break;
	}
}

void fsm_led2_run(){
	switch(mode_led2){
		case MODE_LED_INIT:
			setTimer2(led_green*1000);
			mode_led2 = MODE_LED_2;
		break;
		case MODE_LED_1:
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
			if(timer2_flag == 1){
				mode_led2 = MODE_LED_2;
				setTimer2(led_green*1000);
			}
		break;
		case MODE_LED_2:
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
			if(timer2_flag == 1){
				mode_led2 = MODE_LED_3;
				setTimer2(led_yellow*1000);
			}
		break;
		case MODE_LED_3:
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
			if(timer2_flag == 1){
				mode_led2 = MODE_LED_1;
				setTimer2(led_red*1000);
			}
		break;
	}
}
