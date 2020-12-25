#include <stdio.h>
int main()
{
    int num,tmp,tmp1;
    char res[20];
    int i = 0;
    int k;

    printf("\nex2:\n");
    scanf("%d", &num);
    tmp = num;

    while(tmp){
        tmp=tmp/10;
        i++;
    }

    tmp=num;
    for(k=0;k<i;k++)
    {
        tmp1=tmp%10;
        res[i-k-1]=tmp1+0x30;
        tmp=tmp/10;
    }

    printf("result = %s\n",res);
    return 0;
}

