//1+1/2+1/3+1/4...+1/100求和
#include <stdio.h>
int main(void)
{
    int i = 1;
    float sum = 0;
    for (i = 1; i <= 100; i++)
        sum = sum + 1.0 / i;
    //更简单的写法为sum = sum + 1 / (float)(i)
    printf("%f\n", sum);
    return 0;
}
