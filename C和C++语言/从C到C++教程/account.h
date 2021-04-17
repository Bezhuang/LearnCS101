//2、类与对象的头文件
class Account //类声明
{
private: //隐藏数据成员
    int no;
    char name[10];
    float money;
public: //开放函数成员
    void Deposit();
    void Withdraw();
    void Show();
    Account(int iniNo, char* iniName, float iniMoney);
    //构造函数，公有权限
};