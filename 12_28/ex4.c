/******************************************************************************
*
*ex4 shift
*
******************************************************************************/

#include<stdio.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    int i;
    int* res=(int*)malloc(35*sizeof(int));
    res=res+5;

    for(i=0;i<30;i++)
    {
        *(res+i)=rand()%100;
    }
     for(i=0;i<30;i++)
    {
        printf("%d ",*(res+i));
    }
    printf("\n");
    
    for(i=0;i<5;i++)
    {
        *(res-5+i)=*(res+25+i);
    }
    for(res=res-5,i=0;i<30;i++)
    {
        printf("%d ",*(res+i));
    }

    printf("\n");
    free(res);
    return 0;
}