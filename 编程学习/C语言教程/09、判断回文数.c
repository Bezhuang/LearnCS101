//�ж�����������Ƿ��ǻ�����
#include <stdio.h>
int main(void)
{
    int val;
    int m;
    int sum = 0;
    printf("����������Ҫ�жϵ����֣�");
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
