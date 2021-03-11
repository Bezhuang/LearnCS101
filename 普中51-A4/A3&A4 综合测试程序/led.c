#include "led.h"

void LED_Test(void)
{
	u8 i;
	LED_PORT=0xfe;
	delay(20000); 

	while(1)
	{
	
		for(i=0;i<8;i++)
		{
			LED_PORT=~(~0xfe<<i);
			delay(20000); 
			if(KeyValue!=LED_TEST)
			{
				LED_PORT=0xff;
				return;	
			}
		}	
	}		
}


