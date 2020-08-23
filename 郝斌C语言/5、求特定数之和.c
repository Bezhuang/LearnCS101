//求1到100之间所有能被3整除的数之和
#include <stdio.h>
int main(void)
{
    int i;
    int sum = 0;
    for (i = 1; i <= 100; i++)
    {
        if (i % 3 == 0)
            sum = sum + i;
    }
    printf("sum = %d\n", sum);
    return 0;
}
