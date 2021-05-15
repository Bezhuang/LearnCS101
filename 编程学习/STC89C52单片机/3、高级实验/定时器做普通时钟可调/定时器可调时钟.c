/*-----------------------------------------------
     ʵ�����ƣ����ڶ�ʱ��T0�Ŀɵ�ʱ�ӡ�
		 ����˵����
				 LSA=>P2^2;
				 LSB=>P2^3;
				 LSC=>P2^4;
				 P0=>�����λѡ
				 P3=>��������
------------------------------------------------*/
#include<reg52.h> //����ͷ�ļ���һ���������Ҫ�Ķ���ͷ�ļ��������⹦�ܼĴ����Ķ���

#define KeyPort P3 //���尴���˿�
#define u8 unsigned char
#define u16 unsigned int
#define DataPort P0 //�������ݶ˿� ����������DataPort ����P0 �滻

//sbit LATCH1=P2^2;//��������ʹ�ܶ˿� ������
//sbit LATCH2=P2^3;//                 λ����
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

sbit k1=P3^1;
sbit k2=P3^0;
sbit k3=P3^2;
sbit k4=P3^3;

unsigned char hour,minute,second;//����ʱ����

bit UpdateTimeFlag;//�����ʱ���־

unsigned char code dofly_DuanMa[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};// ��ʾ����ֵ0~9
unsigned char code dofly_WeiMa[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};//�ֱ��Ӧ��Ӧ������ܵ���,��λ��

u8 code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//��ʾ0~F��ֵ

unsigned char TempData[8],Key_Num; //�洢��ʾֵ��ȫ�ֱ���

void DelayUs2x(unsigned char t);//us����ʱ�������� 
void DelayMs(unsigned char t); //ms����ʱ
void DigDisplay();//�������ʾ����
void KeyScan();//����ɨ��
void     Init_Timer0(void);//��ʱ����ʼ��
/*------------------------------------------------
                    ������
------------------------------------------------*/
void delay(u16 i)
{
	while(i--);	
}   
/*--------------------------------------------------*/
void main (void)
{
//unsigned char num;                  

Init_Timer0();

while (1)         //��ѭ��
  {
    				KeyScan();	
					switch(Key_Num)
						{
									case 1:hour++;if(hour==24)hour=0;Key_Num=0;     //����ʱ�� Сʱ ��1
											 break;
									case 2:hour--;if(hour==255)hour=23;Key_Num=0;    //����ʱ�� Сʱ��1
										 break;
									case 3:minute++;if(minute==60)minute=0;Key_Num=0;      //���Ӽ�1
										 break;
									case 4:minute--;if(minute==255)minute=59;Key_Num=0;    //���Ӽ�1
										 break;
									default:break;
						} 
//					if(UpdateTimeFlag==1)
//					 {
//								UpdateTimeFlag=0;

							 TempData[0]=dofly_DuanMa[hour/10]; //ʱ			//���ݵ�ת���������ǲ��������0~9����ʾ,�����ݷֿ�
							 TempData[1]=dofly_DuanMa[hour%10];
							 TempData[2]=0x40;					    	        //����"-"
							 TempData[3]=dofly_DuanMa[minute/10];//��
							 TempData[4]=dofly_DuanMa[minute%10];
							 TempData[5]=0x40;
							 TempData[6]=dofly_DuanMa[second/10];//��
							 TempData[7]=dofly_DuanMa[second%10];	
						   
							DigDisplay();
//						}
					// DigDisplay();
 }
}

/*------------------------------------------------
 ��ʾ���������ڶ�̬ɨ�������
 ������� FirstBit ��ʾ��Ҫ��ʾ�ĵ�һλ���縳ֵ2��ʾ�ӵ���������ܿ�ʼ��ʾ
 ������0��ʾ�ӵ�һ����ʾ��
 Num��ʾ��Ҫ��ʾ��λ��������Ҫ��ʾ99��λ��ֵ���ֵ����2
------------------------------------------------*/
void DigDisplay()
{
	u8 i=0;
	for(i=0;i<8;i++)
	{
		switch(i)	 //λѡ��ѡ�����������ܣ�
		{
			case(7):
				LSA=0;LSB=0;LSC=0; break;//��ʾ��0λ
			case(6):
				LSA=1;LSB=0;LSC=0; break;//��ʾ��1λ
			case(5):
				LSA=0;LSB=1;LSC=0; break;//��ʾ��2λ
			case(4):
				LSA=1;LSB=1;LSC=0; break;//��ʾ��3λ
			case(3):
				LSA=0;LSB=0;LSC=1; break;//��ʾ��4λ
			case(2):
				LSA=1;LSB=0;LSC=1; break;//��ʾ��5λ
			case(1):
				LSA=0;LSB=1;LSC=1; break;//��ʾ��6λ
			case(0):
				LSA=1;LSB=1;LSC=1; break;//��ʾ��7λ	
		}
		P0=TempData[i];//���Ͷ���
		delay(100); //���һ��ʱ��ɨ��	
		P0=0x00;//����
	//delay(1000);
	}
} 
/*------------------------------------------------
                    ��ʱ����ʼ���ӳ���
------------------------------------------------*/
void Init_Timer0(void)
{
 TMOD |= 0x01;	  //ʹ��ģʽ1��16λ��ʱ����ʹ��"|"���ſ�����ʹ�ö����ʱ��ʱ����Ӱ��		     
 //TH0=0x00;	      //������ֵ
 //TL0=0x00;
 EA=1;            //���жϴ�
 ET0=1;           //��ʱ���жϴ�
 TR0=1;           //��ʱ�����ش�
}
/*------------------------------------------------
                 ��ʱ���ж��ӳ���
------------------------------------------------*/
void Timer0_isr(void) interrupt 1 
{
 static unsigned int num,i;
 TH0=(65536-2000)/256;//���¸�ֵ 2ms
 TL0=(65536-2000)%256;
 
 // DigDisplay();     // ���������ɨ��
i++;
 if(i==10)        	  //20ms����һ��
    {
	i=0;
	UpdateTimeFlag=1; 	//����ʱ��־λ��1
	}
 num++;
 if(num==500)        //����1s
   {
    num=0;
	second++;
	if(second==60) 		 //�뵽60�����Ӽ�1
	 {
	  second=0;	  
	  minute++;
	  if(minute==60)	//���ӵ�60��Сʱ��1
	    {
		 minute=0;
		 hour++;
		 if(hour==24)		//Сʱ��24������
		   hour=0;
		}
	 }
   
  }
}

/*------------------------------------------------
����ɨ�躯��������ɨ���ֵ
----------------------------------------------*/
void KeyScan()
{
  if(k1==0)		  //��ⰴ��K1�Ƿ���
	{	
		delay(1000);   //�������� һ���Լ10ms
		if(k1==0)	 //�ٴ��жϰ����Ƿ���
		{
			Key_Num=1;
		}
		while(!k1);	 //��ⰴ���Ƿ��ɿ�
	}

		if(k2==0)		  //��ⰴ��K1�Ƿ���
	{	
		delay(1000);   //�������� һ���Լ10ms
		if(k2==0)	 //�ٴ��жϰ����Ƿ���
		{
			Key_Num=2;
		}
		while(!k2);	 //��ⰴ���Ƿ��ɿ�
	}

		if(k3==0)		  //��ⰴ��K1�Ƿ���
	{	
		delay(1000);   //�������� һ���Լ10ms
		if(k3==0)	 //�ٴ��жϰ����Ƿ���
		{
			Key_Num=3;
		}
		while(!k3);	 //��ⰴ���Ƿ��ɿ�
	}

		if(k4==0)		  //��ⰴ��K1�Ƿ���
	{	
		delay(1000);   //�������� һ���Լ10ms
		if(k4==0)	 //�ٴ��жϰ����Ƿ���
		{
			Key_Num=4;
		}
		while(!k4);	 //��ⰴ���Ƿ��ɿ�
	}			
}

