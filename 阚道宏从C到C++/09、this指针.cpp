#include <iostream>
using namespace std;

class Student{
public:
    void setname(char *name);
    void setage(int age);
    void setscore(float score);
    void show();
private:
    char *name;
    int age;
    float score;
};

void Student::setname(char *name){
    this->name = name;
}
void Student::setage(int age){
    this->age = age;
}
void Student::setscore(float score){
    this->score = score;
}
void Student::show(){
    cout<<this->name<<"的年龄是"<<this->age<<"，成绩是"<<this->score<<endl;
}

int main(){
    Student *pstu = new Student;
    pstu -> setname("李华");
    pstu -> setage(16);
    pstu -> setscore(96.5);
    pstu -> show();

    return 0;
}