#include <stdio.h>
int main(void)
{
    int i = 10;
    int *p = &i;
    int **q = &p;
    int ***r = &q; //r��int **���ͣ�ֻ�ܴ��int **���ͱ�����ַ
}