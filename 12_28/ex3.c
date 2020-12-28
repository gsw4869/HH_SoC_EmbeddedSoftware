/******************************************************************************
*
*ex3 reverse
*
******************************************************************************/

#include<stdio.h>

int main()
{
    int i;
    char* str=(char*)malloc(20*sizeof(char));

    printf("input char string\n");
    scanf("%[^\n]s",str);
    if(strlen(str)>20)
    {
        printf("error,strlen>20\n");
        exit(0);
    }
    for(i=0;i<strlen(str);i++)
    {
        printf("%c",*(str+strlen(str)-1-i));
    }
    printf("\n");

    free(str);
    return 0;
}