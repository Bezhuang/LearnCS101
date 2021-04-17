//求圆形和长方形的面积和周长
#include <iostream>
using namespace std;
//类声明
class Circle
{
public:
    double r;
    double CArea();
    double CLen();
};

class Rectangle
{
    public:
        double a, b;
        double RArea();
        double RLen();
};
//类实现
double Circle::CArea()
{
    return(3.14 * r * r);
}
double Circle::CLen()
{
    return (3.14 * 2 * r);
}

double Rectangle::RArea()
{
    return(a * b);
}
double Rectangle::RLen()
{
    return(2 * (a + b));
}
//使用
int main()
{
    Circle obj1;
    Rectangle obj2;
    
    cin >> obj1.r >> obj2.a >> obj2.b;
    cout << obj1.CArea() << endl << obj1.CLen() << endl;
    cout << obj2.RArea() << endl << obj2.RLen() << endl;
    return 0;
}