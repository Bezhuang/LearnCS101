//�����鵵
#include <stdio.h>
int main(void)
{
    float score;
    printf("���������Ŀ��Գɼ���");
    scanf("%f", &score);
    if (score > 100)
        printf("�������Σ�\n");
    else if (score >= 90)
        printf("����\n");
    else if (score >= 80)
        printf("����\n");
    else if (score >= 60)
        printf("����\n");
    else
        printf("�����񣬼���Ŭ��\n");
    return 0;
}
