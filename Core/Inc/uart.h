/*
 * uart.h
 *
 *  Created on: Dec 6, 2022
 *      Author: anhni
 */

#ifndef INC_UART_H_
#define INC_UART_H_
#include <stdio.h>
#include "main.h"
#include "global.h"
#include "software_timer.h"

void print_traffic_time();
void print_red_time(int counter);
void print_green_time(int counter);
void print_yellow_time(int counter);
void print_time();
void buzzer();
#endif /* INC_UART_H_ */
