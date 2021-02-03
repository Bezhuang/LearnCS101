#include <iostream>
using namespace std;
#include "BorderCircle.h"

double BorderCircle::InnerArea()
{
    double x = CRadius();
    return (3.14 * (x - w)) * (x - w);
}
double BorderCircle::BorderArea()
{
    return(CArea() - InnerArea());
}
void BorderCircle::input()
{
    Circle::input();
    cin >> w;
}

int main()
{
    BorderCircle obj; // 定义1个派生类BorderCircle的对象obj
// 调用派生类对象obj中的新增函数成员Input，输入半径和边框宽度
    obj.input( ); // 调用的是新增成员Input，重名的基类成员Input被覆盖了
// 调用obj中的基类函数成员CArea和CLen，计算并显示圆的面积和周长
    cout << obj.CArea( ) << "," << obj.CLen( ) << endl;
// 调用obj中的新增成员InnerArea和BorderArea，计算并显示内圆和边框的面积
    cout << obj.InnerArea( ) << "," << obj.BorderArea( ) << endl;
    return 0;
}