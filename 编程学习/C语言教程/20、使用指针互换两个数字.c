/*
注意形参和实参以及数据类型
指针指向地址，且地址不能互换
*/
#include <stdio.h>
void huhuan(int *p, int *q) //接收实参数据的是p和q
{
    int t;
    t = *p;
    *p = *q;
    *q = t;
}
int main(void)
{
    int a = 3;
    int b = 5;
    huhuan(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}