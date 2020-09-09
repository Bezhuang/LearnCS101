# include <stdio.h>
# include <string.h>
struct Student
{
	int age;
	char sex;
	char name[100];
}; //分号不能省
void InputStudent(struct Student *);
void OutputStudent(struct Student ss);
int main(void)
{
	struct Student st; 
	InputStudent(&st); //对结构体变量输入  必须发送st的地址
//	printf("%d %c %s\n", st.age, st.sex, st.name);
	OutputStudent(st); //对结构体变量输出  可以发送st的地址也可以直接发送st的内容
	return 0;
}
void OutputStudent(struct Student ss)
{
	printf("%d %c %s\n", ss.age, ss.sex, ss.name);
}
void InputStudent(struct Student * pstu) //pstu只占4个字节
{
	(*pstu).age = 10;
	strcpy(pstu->name, "张三");//字符拷贝函数，要引入<string.h>库
	pstu->sex = 'F';	
}
