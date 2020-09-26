//完整的求最大值函数模板max
#include <iostream>
using namespace std;

template <typename T>
T max(Tx, Ty) //使用类型参数T来指定函数的类型，形参x和y的类型
{
    return (x > y ? x : y);
}

int main()
{
    cout << max(5, 10) << endl;
    cout << max(5.2, 10.2) << endl;
    return 0;
}