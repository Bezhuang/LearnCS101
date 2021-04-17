//求1到100之间奇数和偶数的和和个数以及平均值
#include <stdio.h>
int main(void)
{
    int i;
    int odd_sum = 0;
    int odd_count = 0;
    double odd_average;
    int even_sum = 0;
    int even_count = 0;
    double even_average;
    for (i = 1; i <= 100; i++)
    {
        if (i % 2 == 0)
        {
            even_sum += i;
            even_count += 1;
        }
        else
        {
            odd_sum += i;
            odd_count += 1;
        }
    }
    odd_average = 1.0 * odd_sum / odd_count;
    even_average = 1.0 * even_sum / even_count;
    printf("奇数和=%d\n奇数个数=%d\n奇数平均值=%lf\n", odd_sum, odd_count, odd_average);
    printf("偶数和=%d\n偶数个数=%d\n偶数平均值=%lf\n", even_sum, even_count, even_average);
    return 0;
}