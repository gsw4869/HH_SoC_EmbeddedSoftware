#include <stdio.h>
typedef struct QU
{
    int *data;
    int front;
    int rear;
}Qu;
void initQu(Qu *qu_q)
 {
     qu_q->data = (int *)malloc(sizeof(int)*7);
     
     if(qu_q->data != NULL)
     {
        qu_q->front = qu_q->rear = 0;
     }
 }
void inqu(Qu *qu_q,int value)
{
    if(((qu_q->rear+1)%7)!=qu_q->front)
    {
        qu_q->data[qu_q->rear]=value;
        qu_q->rear=(qu_q->rear+1)%7;
    }
    else 
    {
        printf("Full\n");
    }
}
void outqu(Qu *qu_q,int *value)
{
    if(qu_q->rear!=qu_q->front)
    {
        *value=qu_q->data[qu_q->front];
        qu_q->front=( qu_q->front+1)%7;
    }
}
void print(Qu *qu_q)
{
    int a=qu_q->front;
    while(a!=qu_q->rear)
    {
        printf("%d: %d \n",a,qu_q->data[a]);
        a=(a+1)%7;
    }
}
int main()
{
    int num[6]={4,67,23,58,45,11};
    int i=0;
    int Value;
    Qu a;
    initQu(&a);
    for(i=0;i<=5;i++)
    {
        inqu(&a,num[i]);
    }
    printf("第一次 \n");
    print(&a);
    for(i=0;i<=2;i++)
    {
        outqu(&a,&Value);
    }
    printf("第二次 \n");
    print(&a);
    inqu(&a,99);
    inqu(&a,100);
    inqu(&a,95);
    printf("第三次 \n");
    print(&a);
    return 0;
}