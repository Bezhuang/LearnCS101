//为复数类重载双目运算符"+"

/*重载为复数类的函数成员
class Complex
{
private:
double real, image;
public:
Complex(double x=0, double y=0)
{ real = x; image = y; }
Complex(Complex &c)
{ real = c.real; image = c.image; }
void Show( )
{
cout<<real<<"+"<<image<<"i"<<endl;
}
Complex operator +( Complex c )
{
Complex result ;
result.real = real + c.real ;
result.image = image + c.image ;
return result ;
}
} ;
*/

/*重载为为复数类的友元函数
class Complex
{
private:
double real, image;
public:
Complex(double x=0, double y=0)
{ real = x; image = y; }
Complex(Complex &c)
{ real = c.real; image = c.image; }
void Show( )
{
cout<<real<<"+"<<image<<"i"<<endl;
}
friend Complex operator +(Complex c1, Complex c2) ;
} ;
Complex operator +( Complex c1, Complex c2 )
{
Complex result ;
result.real = c1.real + c2.real ;
result.image = c1.image + c2.image ;
return result ;
}
*/