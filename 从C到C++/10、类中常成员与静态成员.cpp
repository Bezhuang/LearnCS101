//圆形水池类CirclePool的类的定义
#include <iostream>
using namespace std;
class CirclePool
{
private:
    static double price;
    // const double price;
    double r;
public:
    /*CirclePool(double p1 = 0, double p2 = 0):price(p1){ r = p2; } 构造函数*/
    CirclePool(double p1 = 0, double p2 = 0){ r = p2; }
    double GetPrice() { return price; }
    void SetRadius(double x)
    {
        if (x <= 0) { r = 0; cout << "" << endl; }
        else r = x;
    }
    double GerRadius() { return r; }
    double GetCost() { return (3.14 * r * r * price); }
};
double CirclePool::price = 10;

int main()
{
    double totalCost = 0;
    double r1, r2; cin >> r1 >> r2;
    CirclePool pool1(10,r1), pool2(10,r2);
    pool1.SetRadius(r1);
    totalCost += pool1.GetCost();
    pool2.SetRadius(r2);
    totalCost += pool2.GetCost();
    cout << totalCost << endl;
    return 0;
}