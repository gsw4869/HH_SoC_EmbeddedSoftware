/******************************************************************************
*
*ex1 sum
*
******************************************************************************/

#include<stdio.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    int i,sum,mode;
    int res[10];
    printf("input mode(0:manual 1:random)\n");
    scanf("%d",&mode);

    if(mode==0)
    {
        printf("input 10 int\n");
        for(sum=0,i=0;i<10;i++)
        {
            scanf("%d",res+i);
            if(res[i]%2)
            {
                sum+=res[i];
            }
        }
    }
    else 
    {
        for(sum=0,i=0;i<10;i++)
        {
            *(res+i)=rand()%100;
            printf("%d ",*(res+i));
            if(res[i]%2)
            {
                sum+=res[i];
            }
        }
    }
    
    printf("\nresult is %d\n",sum);    
    return 0;
}