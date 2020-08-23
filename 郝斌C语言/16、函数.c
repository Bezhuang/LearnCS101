//函数的第一个例子
#include <stdio.h>
void max(int i, int j) //i和j是形式参数（形参）
{
    if (i > j)
        printf("%d\n", i);
    else
        printf("%d\n", j);
}
int main(void)
{
    int a, b, c, d, e, f;
    a = 1, b = 2, c = 3, d = 9, e = -5, f = 100;
    max(a, b);
    max(c, d);
    max(e, f);
    return 0;
}
