#include <stdio.h>
int main()
{
    unsigned int a;
    unsigned int b;

    printf("\nex4:\n");
    printf("input a hex number\n");
    scanf("%x",&a);

    b=(a<<24)>>28;
    printf("result is %x\n",b);

    return 0;
}