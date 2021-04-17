//任意两数互换
#include <stdio.h>
int main(void)
{
    int i = 3;
    int j = 4;
    int t;
    t = i;
    i = j;
    j = t;
    printf("i=%d, j =%d\n", i, j);
    return 0;
}