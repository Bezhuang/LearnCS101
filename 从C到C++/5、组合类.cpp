//组合4、代码重用类.cpp中的类
#include <iostream>
using namespace std;
#include "TriCircle.h"

double TriCircle::TArea()
{
    double totalArea;
    totalArea = c0.CArea() + c1.CArea() + c2.CArea();
    return totalArea;
}
double TriCircle::TLen()
{
    double totalLen;
    totalLen = c0.CLen() + c1.CLen() + c2.CLen();
    return totalLen;
}

int main()
{
    TriCircle obj;
    obj.c0.input();
    cout << obj.c0.CArea() << "," << obj.c0.CLen() << endl;
    obj.c1.input(); cout << obj.c1.CArea() << "," << obj.c1.CLen() << endl;
    obj.c2.input(); cout << obj.c2.CArea() << "," << obj.c2.CLen() << endl;
    cout<<obj.TArea()<<","<<obj.TLen()<< endl;
    return 0;
}