//只是定义一个新的数据类型，并没有定义变量
struct Student
{
    int age;
    float score;
    char sex;
};
int main (void)
{
    struct Student st = { 80, 66.6, 'F' };
}

/*
也可以
struct Student
{
    int age;
    float score;
    char sex;
}st;   （只能定义一次）
或
struct
{
    int age;
    float score;
    char sex;
} Student;
但这两种都不推荐，尽量不要用
*/