# include <stdio.h>
struct Student
{
    int age;
    float score;
    char sex;
};
int main(void)
{
    struct Student st = { 80,66.6,'F' }; //��ʼ���������ͬʱ����ʼֵ
    struct Student* pst = &st; //&st����ת��Ϊst
    pst->age = 88; //�ڶ��ַ�ʽ
    st.age = 10; //��һ�ַ�ʽ
    return 0;
}