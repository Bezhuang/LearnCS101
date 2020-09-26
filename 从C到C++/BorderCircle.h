#include "Circle.h"
class BorderCircle :public Circle //公有继承Circle类
{
    public:
        double w;
        double InnerArea();
        double BorderArea();
        void input();
};