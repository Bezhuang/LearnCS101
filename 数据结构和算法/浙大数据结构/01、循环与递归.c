#include <stdio.h>
void PrintN();
void PrintM();
int main()
{
    int N;
    scanf("%d", &N);
    PrintN(N);
    PrintM(N);
    return 0;
}
void PrintN(int N)//ѭ��ʵ��
{
    int i;
    for (i = 1; i <=N; i++)
        printf("%d\n", i);
    return;
}
void PrintM(int N)//�ݹ�ʵ��
{
    if(N)
        {
        PrintM(N - 1);
        printf("%d\n", N);
        }
    return;
}