#ifndef _42Motor_h
#define _42Motor_h
#endif 

#include "reg52.h"

#define u8 unsigned char
#define u16 unsigned int
	
//定义电机控制io
sbit INA=P1^0;
sbit INB=P1^1;
sbit INC=P1^2;
sbit IND=P1^3;



extern bit 	B_M_Run;
void Motor_Delay1ms(u16 c) ;  //误差 0us
void Motor_Run(bit dir,u16 sudu);

