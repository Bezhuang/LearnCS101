#include <stdio.h>
#include <malloc.h>
int main(void)
{
    int a[5]; //���intռ4���ֽڣ�������ռ20���ֽڣ�ÿ4���ֽڵ���һ��int����ʹ��
    int len;
    int *pArr;
    int i;
    printf("��������Ҫ��ŵ�Ԫ�صĸ���:");
    scanf("%d", &len);
    pArr = (int *)malloc(4 * len);
    //��̬������һ��һά�����ͬ�� int pArr[len];
    for (i = 0; i < len; i++)
    {
        printf("��������Ҫ��ŵĵ�%d��Ԫ��:", i);
        scanf("%d", &pArr[i]);
    } //�Զ�̬һά���鸳ֵ
    for (i = 0; i < len; i++)
        printf("%d\t", pArr[i]); //�Զ�̬һά�������
    free(pArr);                  //�ͷŵ���̬���������
    return 0;
}