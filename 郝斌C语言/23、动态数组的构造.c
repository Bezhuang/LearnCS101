#include <stdio.h>
#include <malloc.h>
int main(void)
{
    int a[5]; //如果int占4个字节，则本数组占20个字节，每4个字节当作一个int变量使用
    int len;
    int *pArr;
    int i;
    printf("请输入你要存放的元素的个数:");
    scanf("%d", &len);
    pArr = (int *)malloc(4 * len);
    //动态构造了一个一维数组等同于 int pArr[len];
    for (i = 0; i < len; i++)
    {
        printf("请输入你要存放的第%d个元素:", i);
        scanf("%d", &pArr[i]);
    } //对动态一维数组赋值
    for (i = 0; i < len; i++)
        printf("%d\t", pArr[i]); //对动态一维数组输出
    free(pArr);                  //释放掉动态分配的数组
    return 0;
}