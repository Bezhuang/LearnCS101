//一个学生成绩单向量的C++演示程序（类类型向量）
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{
public:
    char name[9];
    float score;
    bool operator<(Student x) // 重载运算符<：按成绩比较大小。其用途是指定排序规则
    {
        if (score < x.score) return true;
        else return false;
    }
};

int main()
{
    vector <Student> sv; // 定义1个类Student类型的向量sv
    // 添加3个向量元素
    Student s;
    strcpy( s.name, "张三"); s.score = 92; sv.push_back( s );
    strcpy( s.name, "李四"); s.score = 86; sv.push_back( s );
    strcpy( s.name, "王五"); s.score = 95; sv.push_back( s );
    sort( sv.begin( ), sv.end( ) ); // 对向量sv进行排序。排序时将使用重载的运算符“<”
    // 显示排序后的结果
    vector <Student> :: iterator svit; // 定义1个向量类的容器迭代器svit
    for ( svit = sv.begin( ); svit < sv.end( ); svit++ ) // 通过容器迭代器svit遍历向量
        cout << svit->name << ", " << svit->score << endl; // 显示向量内容
    return 0;
}

/*
一个学生成绩单向量的C++演示程序（结构体类型向量）
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct // 定义保存学生成绩的结构体Student
{
    char name[9] ;
    float score ;
} Student ;

bool compStudent( Student x, Student y) // 比较函数：按姓名比较大小
{
    if (strcmp(x.name, y.name) < 0) return true; // 按字符串规则来比较姓名
    else return false;
}

int main()
{
    vector <Student> sv; // 定义1个结构体Student类型的向量sv
    // 添加3个向量元素
    Student s;
    strcpy( s.name, "张三"); s.score = 92; sv.push_back( s );
    strcpy( s.name, "李四"); s.score = 86; sv.push_back( s );
    strcpy( s.name, "王五"); s.score = 95; sv.push_back( s );
    
    sort( sv.begin( ), sv.end( ), compStudent ); // 对向量sv进行排序，比较函数为compStudent
    
    // 显示排序后的结果
    vector <Student> :: iterator svit; // 定义1个向量类的容器迭代器svit
    for ( svit = sv.begin( ); svit < sv.end( ); svit++ ) // 通过容器迭代器svit遍历向量
        cout << svit->name << ", " << svit->score << endl; // 显示向量内容
    return 0;
}
*/