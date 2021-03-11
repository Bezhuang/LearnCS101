#ifndef _key_H
#define key_H

#include<reg52.h>

#ifndef u8
#define u8 unsigned char
#endif 
#ifndef u16
#define u16 unsigned int
#endif


//********************PIN define*************************//
#define GPIO_KEY P1



void delay(u16 i);
u8 KeyDown(void);
#endif
