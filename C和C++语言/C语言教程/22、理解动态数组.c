#include <stdio.h>
#include <malloc.h>
void f(int *q) //q��p��һ�ݿ�����������
{
    *q = 200;
}
int main(void)
{
    int i = 5;
    int *p = (int *)malloc(sizeof(int));
    //�ֳ�p��ռ�ľ�̬���䵽�ڴ��p��ָ��Ķ�̬������ڴ�
    *p = 10;
    printf("%d\n", *p);
    f(p); //p��int *p����
    printf("%d\n", *p);
    free(p);
    return 0;
}