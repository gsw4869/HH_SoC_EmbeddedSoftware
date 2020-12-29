#include <stdio.h>
struct Date
{
    int year;
    int month;
    int day;
}date;
int count(int Year,int Month,int Day)
{
    int m,d=0;
    int mday[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((Year%4==0 && Year%100!=0) || (Year%400==0))
    {
        mday[1]=29;
    }
    for(m=0;m<Month-1;m++)
    {
        d+=mday[m];
    }
    d+=Day;
    return d;
}
int main()
{
    int Day;
    int Mday[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("请输入年份 \n");
    scanf("%d",&date.year);
    while(1)
    {
        if(date.year<0)
        {
            printf("请输入正常的年份 \n");
            scanf("%d",&date.year);
        }
        else
        {
            break;
        }
    }
    if((date.year%4==0 && date.year%100!=0) || (date.year%400==0))
    {
        Mday[1]=29;
    }
    printf("请输入月份 \n");
    scanf("%d",&date.month);
    while(1)
    {
        if((date.month>=13)||(date.month<0))
        {
            printf("请输入正常的月份 \n");
            scanf("%d",&date.month);
        }
        else
        {
            break;
        }
    }
    printf("请输入日期 \n");
    scanf("%d",&date.day);
    while(1)
    {
        if((date.day>Mday[date.month-1])||(date.day<0))
        {
            printf("请输入正常的日期 \n");
            scanf("%d",&date.day);
        }
        else
        {
            break;
        }
    }
    printf("%d,%d,%d \n",date.year,date.month,date.day);
    Day=count(date.year,date.month,date.day);
    printf("您所输入的日期是今年的第 %d 天\n",Day);
    return 0;
}