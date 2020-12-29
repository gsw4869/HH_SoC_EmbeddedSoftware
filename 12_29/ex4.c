#include<stdio.h>
#include<time.h>
typedef struct Order{
    char type[100];
    int price;
    int maketime;
    char remarks[100];
    struct order* next;
}order;

typedef struct link_q{
    order* front;
    order* rear;
}linkq;

void Enqueue(linkq* Q)
{
    order* newNode = (order*)malloc(sizeof(order));
    if(newNode==NULL)
    {
        printf("Can not allocate memory\n");
        return;
    }
    printf("Input what you want to order(a,b,c,d).\n");
    scanf("%s",newNode->type);
    if(strcmp(newNode->type,"a")==0)
    {
        newNode->price = 10;
    }
    else if(strcmp(newNode->type,"b")==0)
    {
        newNode->price = 20;
    }
    else if(strcmp(newNode->type,"c")==0)
    {
        newNode->price = 30;
    }
    else if(strcmp(newNode->type,"d")==0)
    {
        newNode->price = 40;
    }
    else
    {
        printf("Do not have that.\n\n");
        return;
    }
    printf("The price is %d.\n",newNode->price);
    printf("\nInput your remarks. \n");
    scanf("%s",newNode->remarks);
    printf("\n%s,%d,%s ordered\n\n",newNode->type,newNode->price,newNode->remarks);
    newNode->maketime=time(NULL);
    newNode->next=NULL;
    Q->rear->next = newNode;
    Q->rear = newNode;
    return;
}

void Dequeue(linkq* Q)
{
    order* node;
    if(Q->rear==Q->front)
    {
        printf("No remaining orders.\n\n");
        return;
    }
    node = Q->front->next;
    Q->front->next=node->next;
    if(Q->rear==node)
    {
        Q->rear = Q->front;
    }
    printf("%s,%d,%s finished,time:%d s\n\n",node->type,node->price,node->remarks,time(NULL)-node->maketime);
    free(node);
    return;
}

int main()
{
    int mode;
    order* s=(order*)malloc(sizeof(order));
    order* s1;
    s->next=NULL;
    linkq q;
    q.front=s;
    q.rear=s;
    while(1)
    {
        printf("input mode: \n0:order \n1:finish \n2:show all\n");
        scanf("%d",&mode);
        if(mode==0)
        {
            Enqueue(&q);
        }
        else if (mode==1)
        {
            Dequeue(&q);
            s1=q.front->next;
            if(s1==NULL)
            {
                printf("No remaining orders.\n\n");
                continue;
            }
            printf("remaining orders:\n");
            for(;s1!=NULL;s1=s1->next)
            {
               printf("%s,%d,%s\n",s1->type,s1->price,s1->remarks); 
            }
            printf("\n");
        }
        else
        {
            s1=q.front->next;
            if(s1==NULL)
            {
                printf("No remaining orders.\n\n");
                continue;
            }
            printf("\nremaining orders:\n");
            for(;s1!=NULL;s1=s1->next)
            {
               printf("%s,%d,%s\n",s1->type,s1->price,s1->remarks); 
            }
            printf("\n");
        }

    }
    return 0;
}