#ifndef _bjmoto_H
#define	_bjmoto_H

#include "public.h"


sbit MOTOA = P1^0;
sbit MOTOB = P1^1;
sbit MOTOC = P1^2;
sbit MOTOD = P1^3; 	

#define SPEED 200 


void BJMOTO_Test(void);


#endif