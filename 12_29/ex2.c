
#include "stdio.h"
#include"string.h"
#include"stdlib.h"

struct Player
{
    char name[50];
    int arrival;
    int score;
};
struct Player Players[1000];
int num=0;
void Player_Input()
{   //输入
    while(1)
    {
            printf("请输入姓名：");
            scanf("%s",Players[num].name);
            getchar();
            printf("请输入报到与否，1表示报到，0表示缺席");
            scanf("%d",&Players[num].arrival);
            getchar();
            printf("请输入马拉松成绩");
            scanf("%d",&Players[num].score);
            getchar();
            num++;
            printf("是否继续？（y/n）");
            if (getchar()=='n')
            {
                    break;
            }
    }
}
int Player_Searchbyname(char na[])
{   //查找
    int i;
    for(i=0;i<num;i++)
        {
            if(strcmp(Players[i].name,na)==0)
            {
                    return i;
            }


    }
    return -1;
}
void Player_Display(int index)
{
    printf("%s \n",Players[index].name);
    printf("%d \n",Players[index].arrival);
    printf("%d \n",Players[index].score);
}
void Player_Select()
{   //选择
    while(1)
    {
        char name[20];
        int index;
        printf("请输入要查询的人的姓名");
        scanf("%s",&name);
        getchar();
        index=Player_Searchbyname(name);
        if (index==-1)
        {
                printf("不存在\n");
        }
        else
        {
                Player_Display(index);
        }
        printf("是否继续？y/n");
        if(getchar()=='n')
        {
                break;
        }
    }
}
void Player_Modify()
{   int index;
    char na[20];
    printf("请输入要修改的人的名字");
    scanf("%s",&na);
    getchar();
    index=Player_Searchbyname(na);
    if(index==-1)
    {
            printf("学生不存在");
    }
    else
    {
            printf("请输入新名字:");
            scanf("%s",&Players[index].name);
            getchar();
            printf("请输入签到与否:");
            scanf("%d",&Players[index].arrival);
            getchar();
            printf("请输入成绩:");
            scanf("%d",&Players[index].score);
            getchar();
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("1.输入\n");
        printf("2.查找\n");
        printf("3.修改\n");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
        case 1:
            Player_Input();
                break;
        case 2:
            Player_Select();
                break;
        case 3:
            Player_Modify();
                break;
        }

    }
    return 0;
}