//Êý×éµÄµ¹ÖÃ
#include <stdio.h>
int main(void)
{
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    int i, j, k;
    i = 0;
    j = 6;
    while (i < j)
    {
        k = a[i];
        a[i] = a[j];
        a[j] = k;
        i++;
        j--;
    }
    for (i = 0; i < 7; i++)
    {
        printf("%d\t", a[i]);
    }
}