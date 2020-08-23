//判断输入的数字是否是回文数
#include <stdio.h>
int main(void)
{
    int val;
    int m;
    int sum = 0;
    printf("请输入您需要判断的数字：");
    scanf("%d", &val);
    m = val;
    while (m)
    {
        sum = sum * 10 + m % 10;
        m /= 10;
    }
    if (sum == val)
        printf("Yes!");
    else
        printf("No!");
    return 0;
}
