/*
��дһ��ģ�����д���˻������C++����
*/
#include <iostream>
using namespace std;
#include <string.h>
#include "account.h"
//���캯��
Account :: Account(int iniNo, char *iniName, float iniMoney)
{
    no = iniNo; strcpy(name, iniName); money = iniMoney;
}

void Account :: Deposit()
{
    cout << "���������";
    float x;
    cin >> x;
    money += x;
    Show();
}

void Account :: Withdraw()
{
    cout << "������ȡ���";
    float x;
    cin >> x;
    if (money < x) cout << "�˻����㡣";
    else money -= x;
    Show();
}

void Account ::Show()
{
    cout << "�˺�" << no << "���˻����Ϊ��" << money << "Ԫ" << endl;
}

int main()
{
    cout <<"�����뿪����Ϣ���˺š��˻�����������" << endl;
    int x; char str[10]; float y;
    cin >> x >> str >> y;
    
    Account obj(x, str, y); //���캯����ʹ��
    
    int choice;
    while (true)
    {
        cout << "1 - ���\n2 - ȡ��\n3 - ��ѯ���\n0 - �˳�\n��ѡ��";
        cin >> choice;
        if (choice == 0) break;
        if (choice == 1) obj.Deposit();
        else if (choice == 2) obj.Withdraw();
        else if (choice == 3) obj.Show();
    }
    return 0;
}
