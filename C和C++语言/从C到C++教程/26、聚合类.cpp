//同5、组合类.cpp类似
#include <iostream>
using namespace std;
#include "pTriCircle.h"
// pTriCircle类：实现部分，具体的函数代码
double pTriCircle :: TArea( ) // 求总面积
{
double totalArea;
totalArea = p0->CArea( ) +
p1->CArea( ) + p2->CArea( );
return totalArea;
}
double pTriCircle :: TLen( ) // 求总周长
{
double totalLen;
totalLen = p0->CLen ( ) +
p1->CLen( ) + p2->CLen( );
return totalLen;
}

int main( )
{
Circle c0, c1, c2; // 先定义3个类Circle的对象c0、c1、c2
c0.input( ); c1.input( ); c2.input( ); // 输入3个圆的半径
pTriCircle obj1; // 定义1个聚合类pTriCircle的对象obj1
// 将obj1中3个对象指针分别指向已经创建的Circle类对象c0、c1、c2
obj1.p0 = &c0; obj1.p1 = &c1; obj1.p2 = &c2;
// 调用obj1中的函数成员TArea和TLen，计算并显示总面积和总周长
cout << obj1.TArea( ) << "," << obj1.TLen( ) << endl;
pTriCircle obj2; // 定义1个聚合类pTriCircle的对象obj2
// 将obj2中3个对象指针也分别指向Circle类对象c0、c1、c2
obj2.p0 = &c0; obj2.p1 = &c1; obj2.p2 = &c2;
// 调用obj2中的函数成员TArea和TLen，计算并显示总面积和总周长
cout << obj2.TArea( ) << "," << obj2.TLen( ) << endl;
return 0;
}
