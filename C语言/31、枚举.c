#include <stdio.h>
//只定义了一个数据类型，并没有定义变量，该数据类型的名字是enum WeekDay
enum WeekDay
{
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

void f(enum WeekDay i) //本函数的目的只是期望接受0～6之间的数字，将形参i定义为枚举型，可以有效的避免传参失误的问题
{
	switch (i)
	{
	case 0:
		printf("Monday!\n");
		break;
	case 1:
		printf("Tuesday!\n");
		break;
	case 2:
		printf("Wednesday!\n");
		break;
	case 3:
		printf("Thursday!\n");
		break;
	case 4:
		printf("Friday!\n");
		break;
	case 5:
		printf("Saturday!\n");
		break;
	case 6:
		printf("Sunday!\n");
		break;  
	}          
}

int main(void)
{
	f(Friday); //虽然FriDay本质上就是5，但直接写成f(5);就是错的， 也不能写成f(10); 考虑为什么！ 嘿嘿
    enum WeekDay day = Wednesday;
    printf("%d\n", day);
	return 0;
}
