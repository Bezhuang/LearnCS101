//��1��100֮��������ż���ĺͺ͸����Լ�ƽ��ֵ
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
    printf("������=%d\n��������=%d\n����ƽ��ֵ=%lf\n", odd_sum, odd_count, odd_average);
    printf("ż����=%d\nż������=%d\nż��ƽ��ֵ=%lf\n", even_sum, even_count, even_average);
    return 0;
}