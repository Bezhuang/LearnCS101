//�纯��ʹ���ڴ�Ļ���
void f(int **p)
{
    //*q����p
}
void g()
{
    int i = 10;
    int *p = &i;
    f(&p); //p��int *���ͣ�&p��int **����
}
int main(void)
{
    g();
    return 0;
}