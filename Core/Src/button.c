
#include "button.h"
#include "main.h"

int button1_flag=0;
int button1_3s_flag=0;
int button2_flag=0;
int button3_flag=0;
int button4_flag=0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int KeyReg4 = NORMAL_STATE;
int KeyReg5 = NORMAL_STATE;
int KeyReg6 = NORMAL_STATE;
int KeyReg7 = NORMAL_STATE;

int KeyReg8 = NORMAL_STATE;
int KeyReg9 = NORMAL_STATE;
int KeyReg10 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;

int KeyReg12 = NORMAL_STATE;
int KeyReg13 = NORMAL_STATE;
int KeyReg14 = NORMAL_STATE;
int KeyReg15 = NORMAL_STATE;

int downtime = 100;
int counter_time = 0;
int TimeOutForKeyPress_1 = 300;
int TimeOutForKeyPress_2 = 100;
int TimeOutForKeyPress_3 = 100;
int TimeOutForKeyPress_4 = 100;
////////////press////////////
int is_Button1_Pressed(){
	if(button1_flag == 1)
	{
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int is_Button1_Pressed_3s(){
	if(button1_3s_flag == 1)
	{
		button1_3s_flag = 0;
		return 1;
	}
	return 0;
}
int is_Button2_Pressed(){
	if(button2_flag == 1)
	{
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int is_Button3_Pressed(){
	if(button3_flag == 1)
	{
		button3_flag =0;
		return 1;
	}
	return 0;
}
int is_Button4_Pressed(){
	if(button4_flag == 1)
	{
		button4_flag =0;
		return 1;
	}
	return 0;
}
///////////subkey////////////

void subKeyProcess_1(){
	button1_flag=1;
}
void subKeyProcess_3s_1(){
	button1_3s_flag=1;
}
void subKeyProcess_2(){
	button2_flag=1;
}
void subKeyProcess_3(){
	button3_flag=1;
}
void subKeyProcess_4(){
	button4_flag=1;
}
void getKeyInput_1(){
  KeyReg10 = KeyReg9;
  KeyReg9 = KeyReg8;
  KeyReg8 = HAL_GPIO_ReadPin(A1_GPIO_Port, A1_Pin);
  if ((KeyReg9 == KeyReg8) && (KeyReg9 == KeyReg10)){
    if (KeyReg10 != KeyReg11){
      KeyReg11 = KeyReg10;

      if (KeyReg10 == PRESSED_STATE){
        TimeOutForKeyPress_1 = 300;
        subKeyProcess_1();
      }
    }else{
       TimeOutForKeyPress_1 --;
        if (TimeOutForKeyPress_1 == 0){
          //KeyReg3 = NORMAL_STATE;
        	if (KeyReg10 == PRESSED_STATE){
        		subKeyProcess_3s_1();
        	}
//        	TimeOutForKeyPress_1 = 100;

        }
    }
  }
}
void getKeyInput_2(){
  KeyReg2 = KeyReg1;
  KeyReg1 = KeyReg0;
  KeyReg0 = HAL_GPIO_ReadPin(A2_GPIO_Port, A2_Pin);
  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
	if (KeyReg2 != KeyReg3){
		KeyReg3 = KeyReg2;
		if (KeyReg2 == PRESSED_STATE){
			button2_flag = 1;
			TimeOutForKeyPress_2 = 300;
		}
    }else{
    	TimeOutForKeyPress_2 --;
    	if (TimeOutForKeyPress_2 == 0){
    		if(KeyReg2 == PRESSED_STATE) button2_flag = 1;
    		TimeOutForKeyPress_2 = 100;
    	}
	}
  }
}


void getKeyInput_3(){
  KeyReg6 = KeyReg5;
  KeyReg5 = KeyReg4;
  KeyReg4 = HAL_GPIO_ReadPin(A3_GPIO_Port, A3_Pin);
  if ((KeyReg5 == KeyReg4) && (KeyReg5 == KeyReg6)){
	  if (KeyReg6 != KeyReg7){
		  KeyReg7 = KeyReg6;
		  if (KeyReg6 == PRESSED_STATE){
			  button3_flag = 1;
			  TimeOutForKeyPress_3 = 300;
		  }
	  }else{
		  TimeOutForKeyPress_3 --;
		  if (TimeOutForKeyPress_3 == 0){
		      	if(KeyReg6 == PRESSED_STATE)button3_flag = 1;
		      	TimeOutForKeyPress_3 = 100;
		  }
	  }
  }
}

void getKeyInput_4(){
  KeyReg14 = KeyReg13;
  KeyReg13 = KeyReg12;
  KeyReg12 = HAL_GPIO_ReadPin(A0_GPIO_Port, A0_Pin);
  if ((KeyReg13 == KeyReg12) && (KeyReg13 == KeyReg14)){
	  if (KeyReg14 != KeyReg15){
		  KeyReg15 = KeyReg14;
		  if (KeyReg14 == PRESSED_STATE){
			  button4_flag = 1;
			  TimeOutForKeyPress_4 = 300;
		  }
	  }else{
		  TimeOutForKeyPress_4 --;
		  if (TimeOutForKeyPress_4 == 0){
		      	if(KeyReg14 == PRESSED_STATE)button4_flag = 1;
		      	TimeOutForKeyPress_4 = 100;
		  }
	  }
  }
}
