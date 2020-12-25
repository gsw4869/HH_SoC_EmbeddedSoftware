/******************************************************************************
*
*ex1: 1,2,3,4 arrange
*
******************************************************************************/

#include<stdio.h>

int main()
{
    int i,j,k,tmp;
    int count=0;

    for(i=1;i<5;i++)
    {
        for(j=1;j<5;j++)
        {
            if(j-i)
            {
                for(k=1;k<5;k++)
                {
                    if((k-j)&&(k-i))
                    {
                        tmp=i*100+j*10+k;
                        printf("%d  ",tmp);
                        count++;
                    }
                }
            }
        }
    }

    printf("\nTotal number is %d\n",count);
    return 0;
}
