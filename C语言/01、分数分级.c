//分数归档
#include <stdio.h>
int main(void)
{
    float score;
    printf("请输入您的考试成绩：");
    scanf("%f", &score);
    if (score > 100)
        printf("这是做梦！\n");
    else if (score >= 90)
        printf("优秀\n");
    else if (score >= 80)
        printf("良好\n");
    else if (score >= 60)
        printf("及格\n");
    else
        printf("不及格，继续努力\n");
    return 0;
}
