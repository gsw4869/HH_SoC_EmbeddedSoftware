/******************************************************************************
*
*ex2 sort
*
******************************************************************************/

#include<stdio.h>

void Sort(int a[], int len)
{
	int i,j,temp;
	for (j = 0; j < len - 1; j++)
	{
		for (i = 0; i < len - 1 - j; i++)
		if (a[i] > a[i + 1])
		{
			temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
	}
}

int main()
{
    int i;
    int res[10];
    printf("input 10 int\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",res+i);
    }
    Sort(res,10);
    printf("result is ");
    for(i=0;i<10;i++)
    {
        printf("%d ",res[i]);    
    }
    return 0;
}