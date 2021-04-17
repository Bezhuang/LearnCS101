/*-----------------------------------------------
     实验名称：基于定时器T0的可调时钟、
		 接线说明：
				 LSA=>P2^2;
				 LSB=>P2^3;
				 LSC=>P2^4;
				 P0=>数码管位选
				 P3=>独立按键
------------------------------------------------*/
#include<reg52.h> //包含头文件，一般情况不需要改动，头文件包含特殊功能寄存器的定义

#define KeyPort P3 //定义按键端口
#define u8 unsigned char
#define u16 unsigned int
#define DataPort P0 //定义数据端口 程序中遇到DataPort 则用P0 替换

//sbit LATCH1=P2^2;//定义锁存使能端口 段锁存
//sbit LATCH2=P2^3;//                 位锁存
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

sbit k1=P3^1;
sbit k2=P3^0;
sbit k3=P3^2;
sbit k4=P3^3;

unsigned char hour,minute,second;//定义时分秒

bit UpdateTimeFlag;//定义读时间标志

unsigned char code dofly_DuanMa[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};// 显示段码值0~9
unsigned char code dofly_WeiMa[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};//分别对应相应的数码管点亮,即位码

u8 code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//显示0~F的值

unsigned char TempData[8],Key_Num; //存储显示值的全局变量

void DelayUs2x(unsigned char t);//us级延时函数声明 
void DelayMs(unsigned char t); //ms级延时
void DigDisplay();//数码管显示函数
void KeyScan();//键盘扫描
void     Init_Timer0(void);//定时器初始化
/*------------------------------------------------
                    主函数
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

while (1)         //主循环
  {
    				KeyScan();	
					switch(Key_Num)
						{
									case 1:hour++;if(hour==24)hour=0;Key_Num=0;     //正常时间 小时 加1
											 break;
									case 2:hour--;if(hour==255)hour=23;Key_Num=0;    //正常时间 小时减1
										 break;
									case 3:minute++;if(minute==60)minute=0;Key_Num=0;      //分钟加1
										 break;
									case 4:minute--;if(minute==255)minute=59;Key_Num=0;    //分钟减1
										 break;
									default:break;
						} 
//					if(UpdateTimeFlag==1)
//					 {
//								UpdateTimeFlag=0;

							 TempData[0]=dofly_DuanMa[hour/10]; //时			//数据的转换，因我们采用数码管0~9的显示,将数据分开
							 TempData[1]=dofly_DuanMa[hour%10];
							 TempData[2]=0x40;					    	        //加入"-"
							 TempData[3]=dofly_DuanMa[minute/10];//分
							 TempData[4]=dofly_DuanMa[minute%10];
							 TempData[5]=0x40;
							 TempData[6]=dofly_DuanMa[second/10];//秒
							 TempData[7]=dofly_DuanMa[second%10];	
						   
							DigDisplay();
//						}
					// DigDisplay();
 }
}

/*------------------------------------------------
 显示函数，用于动态扫描数码管
 输入参数 FirstBit 表示需要显示的第一位，如赋值2表示从第三个数码管开始显示
 如输入0表示从第一个显示。
 Num表示需要显示的位数，如需要显示99两位数值则该值输入2
------------------------------------------------*/
void DigDisplay()
{
	u8 i=0;
	for(i=0;i<8;i++)
	{
		switch(i)	 //位选，选择点亮的数码管，
		{
			case(7):
				LSA=0;LSB=0;LSC=0; break;//显示第0位
			case(6):
				LSA=1;LSB=0;LSC=0; break;//显示第1位
			case(5):
				LSA=0;LSB=1;LSC=0; break;//显示第2位
			case(4):
				LSA=1;LSB=1;LSC=0; break;//显示第3位
			case(3):
				LSA=0;LSB=0;LSC=1; break;//显示第4位
			case(2):
				LSA=1;LSB=0;LSC=1; break;//显示第5位
			case(1):
				LSA=0;LSB=1;LSC=1; break;//显示第6位
			case(0):
				LSA=1;LSB=1;LSC=1; break;//显示第7位	
		}
		P0=TempData[i];//发送段码
		delay(100); //间隔一段时间扫描	
		P0=0x00;//消隐
	//delay(1000);
	}
} 
/*------------------------------------------------
                    定时器初始化子程序
------------------------------------------------*/
void Init_Timer0(void)
{
 TMOD |= 0x01;	  //使用模式1，16位定时器，使用"|"符号可以在使用多个定时器时不受影响		     
 //TH0=0x00;	      //给定初值
 //TL0=0x00;
 EA=1;            //总中断打开
 ET0=1;           //定时器中断打开
 TR0=1;           //定时器开关打开
}
/*------------------------------------------------
                 定时器中断子程序
------------------------------------------------*/
void Timer0_isr(void) interrupt 1 
{
 static unsigned int num,i;
 TH0=(65536-2000)/256;//重新赋值 2ms
 TL0=(65536-2000)%256;
 
 // DigDisplay();     // 调用数码管扫描
i++;
 if(i==10)        	  //20ms更新一次
    {
	i=0;
	UpdateTimeFlag=1; 	//更新时间志位置1
	}
 num++;
 if(num==500)        //大致1s
   {
    num=0;
	second++;
	if(second==60) 		 //秒到60，分钟加1
	 {
	  second=0;	  
	  minute++;
	  if(minute==60)	//分钟到60，小时加1
	    {
		 minute=0;
		 hour++;
		 if(hour==24)		//小时到24，回零
		   hour=0;
		}
	 }
   
  }
}

/*------------------------------------------------
按键扫描函数，返回扫描键值
----------------------------------------------*/
void KeyScan()
{
  if(k1==0)		  //检测按键K1是否按下
	{	
		delay(1000);   //消除抖动 一般大约10ms
		if(k1==0)	 //再次判断按键是否按下
		{
			Key_Num=1;
		}
		while(!k1);	 //检测按键是否松开
	}

		if(k2==0)		  //检测按键K1是否按下
	{	
		delay(1000);   //消除抖动 一般大约10ms
		if(k2==0)	 //再次判断按键是否按下
		{
			Key_Num=2;
		}
		while(!k2);	 //检测按键是否松开
	}

		if(k3==0)		  //检测按键K1是否按下
	{	
		delay(1000);   //消除抖动 一般大约10ms
		if(k3==0)	 //再次判断按键是否按下
		{
			Key_Num=3;
		}
		while(!k3);	 //检测按键是否松开
	}

		if(k4==0)		  //检测按键K1是否按下
	{	
		delay(1000);   //消除抖动 一般大约10ms
		if(k4==0)	 //再次判断按键是否按下
		{
			Key_Num=4;
		}
		while(!k4);	 //检测按键是否松开
	}			
}

