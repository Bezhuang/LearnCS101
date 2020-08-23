//连续数的求和
#include <stdio.h>
int main(void)
{
    int i;
    int sum = 0;
    for (i = 1; i <= 100000; i++)
        sum = sum + i;
    printf("sum = %d\n", sum);
    return 0;
}