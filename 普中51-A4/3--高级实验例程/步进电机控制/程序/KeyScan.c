#include "Key.h"

void KeyScan_Delay1ms(u8 c)   //Îó²î 0us
{
    u8 a,b;
	for (; c>0; c--)
	{
		 for (b=199;b>0;b--)
		 {
		  	for(a=1;a>0;a--);
		 }      
	}
    	
}