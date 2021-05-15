#include <iostream>
using namespace std;

int &plus10(int &r) {
    int m = r + 10;
    return m;  //返回局部数据的引用
}

int main() {
    int num1 = 10;
    int num2 = plus10(num1);
    cout << num2 << endl;
    int &num3 = plus10(num1);
    int &num4 = plus10(num3);
    cout << num3 << " " << num4 << endl;

    return 0;
}