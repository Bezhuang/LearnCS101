//动态构造存放学生信息的结构体数组
# include <stdio.h>
# include <stdlib.h>
struct Student
{
    int age;
    float score;
    char name[100];
};
int main(void)
{
    int len;
    struct Student * pArr;
	int i, j;
	struct Student t;
    //动态的构造一维数组
    printf("请输入学生的个数：\n");
    printf("len = ");
    scanf("%d", &len);
    pArr = (struct Student *)malloc(len * sizeof(struct Student));
    for(i=0;i<len;i++)
        {
        printf("请输入第%d个学生的信息\n",i+1);
        printf("age = ");
        scanf("%d", &pArr[i].age);
        printf("name = ");
        scanf("%s", pArr[i].name);
        //name是数组名，本身已经是数组首元素的地址，不加&
        printf("score = ");
        scanf("%f", &pArr[i].score);
        }
    //冒泡排序
    for(i=0; i<len-1; i++)
    {
        for (j = 0; j < len-1-i; j++)
        {
            if ( pArr[j].score > pArr[j + 1].score)
                {
                t = pArr[j];
                pArr[j] = pArr[j + 1];
                pArr[j + 1] = t;
                }
        }
        
    }
    //输出
    printf("\n\n学生的信息是");
    for (i = 0; i < len; i++)
    {
        printf("第%d名学生的信息是：\n",i+1);
        printf("age = %d\n",pArr[i].age);
        printf("name = %s\n",pArr[i].name);
        printf("score = %f\n",pArr[i].score);
    }
    
    return 0;
}