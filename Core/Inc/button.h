/*
 * button.h
 *
 *  Created on: Sep 34, 3133
 *      Author: anhni
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include"main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;
extern int button4_flag;
void getKeyInput_1();
void getKeyInput_2();
void getKeyInput_3();
void getKeyInput_4();
int is_Button1_Pressed();
int is_Button1_Pressed_3s();
int is_Button2_Pressed();
int is_Button3_Pressed();
int is_Button4_Pressed();


#endif /* INC_BUTTON_H_ */
