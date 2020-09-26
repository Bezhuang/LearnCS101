#include <iostream>
using namespace std;

int Div( int n ) // 求100 ÷ n
{
    if ( n <= 0 ) // 检查异常：如果n<=0，则属于异常情况
        throw ( -1 ); // 异常处理流程：抛出异常，然后退出当前函数的执行
    // 如果没有异常，则执行如下的正常处理流程
    return ( 100 / n ) ;
}


int main( )
{
    int N; // 定义变量N，保存键盘输入的人数
    cin >> N;
    try
    {
        int result = Div( N ); // 调用函数Div进行除法运算
        cout << "100÷" << N << "=" << result << endl; // 显示100 ÷ N的结果
    }
    catch ( int ) // 捕获int型异常
    {
        cout << "输入人数时必须为正整数" << endl; // 向用户显示错误信息
    }
    catch ( ... ) // 捕获任意类型的异常
    {
        cout << "发生了其它异常" << endl; // 向用户显示错误信息
    }
    return 0;
}