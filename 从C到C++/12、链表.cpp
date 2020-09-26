#include <iostream>
#include <string.h>
using namespace std;

typedef struct tagStudent // 定义保存学生成绩的结构体Student，具有双向指针
{
    char name[9] ;
    float score ;
    struct tagStudent *prev, *next; // 定义前向指针prev和后向指针next
} Student ;

int main()
{
    Student *begin ; // 定义指向双向链表首节点的指针变量begin
    begin = new Student; // 创建首节点
    strcpy( begin->name, "张三" ); begin->score = 92;
    begin->prev = 0; begin->next = 0; // 首节点目前还没有前后节点，将前后指针置空
    Student *curNode = begin; // 定义指向当前节点的指针变量curNode
    
    Student *p = new Student; // 创建第2个节点
    strcpy( p->name, "李四" ); p->score = 86;
    curNode->next = p; // 将前一个节点的后向指针next指向新节点
    p->prev = curNode; // 将新节点的前向指针prev指向前一个节点
    p->next = 0; // 将新节点的后向指针next置空
    curNode = p; // 新节点成为当前节点
    
    p = new Student; // 创建第3个节点
    strcpy( p->name, "王五" ); p->score = 95;
    curNode->next = p; // 将前一个节点的后向指针next指向新节点
    p->prev = curNode; // 将新节点的前向指针prev指向前一个节点
    p->next = 0; // 将新节点的后向指针next置空
    curNode = p; // 新节点成为当前节点
    
    curNode = begin ; // 通过指针变量curNode访问链表中的各个节点，显示出学生成绩单
    while (curNode != 0 ) // 循环条件：当前节点不为空
    {
        cout << curNode ->name << ", " << curNode ->score << endl;
        curNode = curNode->next ; // 将指针变量curNode移到下一个节点
    }
    return 0;
}