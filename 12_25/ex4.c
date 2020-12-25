/******************************************************************************
*
*ex4: memory copy
*
******************************************************************************/

#include<stdio.h>

void mcp(unsigned int a,unsigned int b,int size)
{
    int i;
    char* c1=a;
    char* c2=b;
    for(i=0;i<size;i++)
    {
        *(c2+i)=*(c1+i);
    }
}

int main()
{
    char* c1=(char*)malloc(20*sizeof(char));
    char* c2=(char*)malloc(20*sizeof(char));

    unsigned int a=(unsigned int)c1;//source address
    unsigned int b=(unsigned int)c2;//destination address
    
    strcpy(c1,"\nhello\n");
    mcp(a,b,20);

    printf("%s",c2);
    printf("source address: 0x%x\n",a);
    printf("destination address: 0x%x\n",b);
    printf("source address: %p\n",c1);
    printf("destination address: %p\n",c2);

    free(c1);
    free(c2);

    return 0;
}
