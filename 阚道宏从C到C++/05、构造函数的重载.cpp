#include <iostream>
using namespace std;

class Student{
private:
    char *m_name;
    int m_age;
    float m_score;
public:
    Student();
    Student(char *name, int age, float score);
    void setname(char *name);
    void setage(int age);
    void setscore(float score);
    void show();
};

Student::Student(){
    m_name = NULL;
    m_age = 0;
    m_score = 0.0;
}
Student::Student(char *name, int age, float score){
    m_name = name;
    m_age = age;
    m_score = score;
}
void Student::setname(char *name){
    m_name = name;
}
void Student::setage(int age){
    m_age = age;
}
void Student::setscore(float score){
    m_score = score;
}
void Student::show(){
    if(m_name == NULL || m_age <= 0){
        cout<<"成员变量还未初始化"<<endl;
    }else{
        cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
    }
}

int main(){
    //调用构造函数 Student(char *, int, float)
    Student stu("小明", 15, 92.5f);
    stu.show();

    //调用构造函数 Student()
    Student *pstu = new Student();
    pstu -> show();
    pstu -> setname("李华");
    pstu -> setage(16);
    pstu -> setscore(96);
    pstu -> show();

    return 0;
}