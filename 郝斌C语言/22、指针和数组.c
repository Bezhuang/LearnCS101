#include <stdio.h>
void f(int *pArr, int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d  ", pArr[i]);
}
