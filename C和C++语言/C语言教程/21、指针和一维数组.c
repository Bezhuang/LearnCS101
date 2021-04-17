//确定一维数组需要的两个参数
#include <stdio.h>
void f(int *pArr, int len) //第一个元素的地址；数组的长度
{
    int i;
    pArr[3] = 88; //和主函数数组的a[3]是同一个变量
    for (i = 0; i < len; ++i)
        printf("%d\t", *(pArr + i));
}
int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    f(a, 5);
    return 0;
}
