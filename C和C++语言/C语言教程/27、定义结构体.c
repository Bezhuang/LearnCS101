//ֻ�Ƕ���һ���µ��������ͣ���û�ж������
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
Ҳ����
struct Student
{
    int age;
    float score;
    char sex;
}st;   ��ֻ�ܶ���һ�Σ�
��
struct
{
    int age;
    float score;
    char sex;
} Student;
�������ֶ����Ƽ���������Ҫ��
*/