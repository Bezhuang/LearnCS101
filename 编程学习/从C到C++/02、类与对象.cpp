/*
编写一个模拟银行存款账户管理的C++程序
*/
#include <iostream>
using namespace std;
#include <string.h>
#include "account.h"
//构造函数
Account :: Account(int iniNo, char *iniName, float iniMoney)
{
    no = iniNo; strcpy(name, iniName); money = iniMoney;
}

void Account :: Deposit()
{
    cout << "请输入存款金额：";
    float x;
    cin >> x;
    money += x;
    Show();
}

void Account :: Withdraw()
{
    cout << "请输入取款金额：";
    float x;
    cin >> x;
    if (money < x) cout << "账户余额不足。";
    else money -= x;
    Show();
}

void Account ::Show()
{
    cout << "账号" << no << "的账户余额为：" << money << "元" << endl;
}

int main()
{
    cout <<"请输入开户信息（账号、账户名、存款金额）：" << endl;
    int x; char str[10]; float y;
    cin >> x >> str >> y;
    
    Account obj(x, str, y); //构造函数的使用
    
    int choice;
    while (true)
    {
        cout << "1 - 存款\n2 - 取款\n3 - 查询余额\n0 - 退出\n请选择：";
        cin >> choice;
        if (choice == 0) break;
        if (choice == 1) obj.Deposit();
        else if (choice == 2) obj.Withdraw();
        else if (choice == 3) obj.Show();
    }
    return 0;
}
