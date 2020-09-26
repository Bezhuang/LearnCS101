//4、代码重用类.cpp的头文件
class Circle
{
private:
    double r; 
public:
    void input();
    double CRadius();
    double CArea();
    double CLen();
    
    Circle(); //无构造函数
    Circle(double x); //有参构造函数
    Circle(Circle& x); //拷贝构造函数
};
