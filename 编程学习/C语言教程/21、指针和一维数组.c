//ȷ��һά������Ҫ����������
#include <stdio.h>
void f(int *pArr, int len) //��һ��Ԫ�صĵ�ַ������ĳ���
{
    int i;
    pArr[3] = 88; //�������������a[3]��ͬһ������
    for (i = 0; i < len; ++i)
        printf("%d\t", *(pArr + i));
}
int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    f(a, 5);
    return 0;
}
