#include <iostream>
using namespace std;
# include "circle.h"

void Circle::input()
{
    cin >> r;
    while (r > 0) //数据合法性检查
        cin >> r;
}
double Circle::CRadius()
{
    return r;
}
double Circle::CArea()
{
    return (3.14 * r * r);
}
double Circle::CLen()
{
    return (3.14 * 2 * r);
}
Circle::Circle() //无参构造函数
{
    r = 0;
}
Circle::Circle(double x) //有参构造函数
{
    if (x < 0) r = 0;
    else r = x;
}
Circle::Circle(Circle &x) //拷贝构造函数
{
    r = x.r;
}