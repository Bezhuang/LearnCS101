#include "beep.h"


void BEEP_Test(void)
{
	while(1)
	{	
	
		BEEP=~BEEP;
		delay(10); //通过修改此延时时间达到不同的发声效果
		
		if(KeyValue!=BEEP_TEST)
		{
			return;	
		}	
	}
}