# include <stdio.h>
struct Student
{
    int age;
    float score;
    char sex;
};
int main(void)
{
    struct Student st = { 80,66.6,'F' }; //初始化，定义的同时赋初始值
    struct Student* pst = &st; //&st不能转化为st
    pst->age = 88; //第二种方式
    st.age = 10; //第一种方式
    return 0;
}