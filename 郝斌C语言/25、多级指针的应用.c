//跨函数使用内存的基础
void f(int **p)
{
    //*q就是p
}
void g()
{
    int i = 10;
    int *p = &i;
    f(&p); //p是int *类型，&p是int **类型
}
int main(void)
{
    g();
    return 0;
}