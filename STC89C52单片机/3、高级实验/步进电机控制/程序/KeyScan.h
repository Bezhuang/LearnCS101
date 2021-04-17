#ifndef _KeyScan_H
#define KeyScan_H

#include<reg52.h>

#ifndef u8
#define u8 unsigned char
#endif 
#ifndef u16
#define u16 unsigned int
#endif


//********************PIN define*************************//
#define KEY P1


void KeyScan_Delay1ms(u8 c);
#endif
