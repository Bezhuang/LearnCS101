#include <stdio.h>
int main(void)
{
    int i = 10;
    int *p = &i;
    int **q = &p;
    int ***r = &q; //r是int **类型，只能存放int **类型变量地址
}