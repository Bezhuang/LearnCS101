#include "42Motor.h"

	u8 Motor_Step=0;

void Motor_Delay1ms(u16 c)   //Îó²î 0us
{

	for (; c>0; c--)
	{
//		 for (b=199;b>0;b--)
//		 {
//		  	
//		 }      
	}
    	
}
void Motor_Run(bit dir,u16 sudu)
{

	
				switch(Motor_Step)
					{
						case 0: INA=1;INB=0;INC=0;IND=0;if(dir)Motor_Step++;else Motor_Step=7;Motor_Delay1ms(20);break;
									
						case 1: INA=1;INB=0;INC=1;IND=0;if(dir)Motor_Step++;else Motor_Step--;Motor_Delay1ms(20);break;
								
						case 2: INA=0;INB=0;INC=1;IND=0;if(dir)Motor_Step++;else Motor_Step--;Motor_Delay1ms(20);break;
								
						case 3: INA=0;INB=1;INC=1;IND=0;if(dir)Motor_Step++;else Motor_Step--;Motor_Delay1ms(20);break;
								
						case 4: INA=0;INB=1;INC=0;IND=0;if(dir)Motor_Step++;else Motor_Step--;Motor_Delay1ms(20);break;
								
						case 5: INA=0;INB=1;INC=0;IND=1;if(dir)Motor_Step++;else Motor_Step--;Motor_Delay1ms(20);break;
								
						case 6: INA=0;INB=0;INC=0;IND=1;if(dir)Motor_Step++;else Motor_Step--;Motor_Delay1ms(20);break;
									
						case 7: INA=1;INB=0;INC=0;IND=1;if(dir)Motor_Step=0;else Motor_Step--;Motor_Delay1ms(20);break;
								
						
					}
					INA=0;INB=0;INC=0;IND=0;
					Motor_Delay1ms(sudu);
		
//	for(i=0;i<2000;i++)
//	{
//		 INA=0;INB=0;INC=0;IND=0;Motor_Delay1ms(80);
//	
//		 INA=0;INB=0;INC=1;IND=0;Motor_Delay1ms(100);
//		
//		 INA=0;INB=1;INC=0;IND=0;Motor_Delay1ms(100);
//	 
//		INA=0;INB=0;INC=0;IND=1;Motor_Delay1ms(100);
//		
//	}
	
}


