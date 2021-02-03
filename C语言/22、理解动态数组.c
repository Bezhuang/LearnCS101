#include <stdio.h>
#include <malloc.h>
void f(int *q) //q是p的一份拷贝（副本）
{
    *q = 200;
}
int main(void)
{
    int i = 5;
    int *p = (int *)malloc(sizeof(int));
    //分出p所占的静态分配到内存和p所指向的动态分配的内存
    *p = 10;
    printf("%d\n", *p);
    f(p); //p是int *p类型
    printf("%d\n", *p);
    free(p);
    return 0;
}