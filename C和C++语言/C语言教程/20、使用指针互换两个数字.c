/*
ע���βκ�ʵ���Լ���������
ָ��ָ���ַ���ҵ�ַ���ܻ���
*/
#include <stdio.h>
void huhuan(int *p, int *q) //����ʵ�����ݵ���p��q
{
    int t;
    t = *p;
    *p = *q;
    *q = t;
}
int main(void)
{
    int a = 3;
    int b = 5;
    huhuan(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}