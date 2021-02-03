//一个实例化的派生类
#include <iostream>
using namespace std;
//基类Base是一个类模板
template <typename T>
class Base
{
private:
    T a;  //数据成员
public:
    Base(T x)
    {
        a = x;  //构造函数
    }
    void Show()
    {
        cout << "a=" << a << ",";
    }
};
//派生类Derived公有继承类模板Base，派生时实例化
class Derived :public Base <double>
{
private:
    int b; //新增数据成员
public:
    //注意派生类构造函数的写法
    Derived(double p1, int p2):Base <double>(p1)
    {
        b = p2;
    }
    void Show() //新增函数成员覆盖基类同名函数Show()
        {
        Base <double>::Show(); //调用基类同名函数
        cout << "b=" << b << endl;
        }
};

int main()
{
    Derived obj(10.5, 6); //定义派生类Derived的对象obj
    obj.Show();
    return 0;
}