#include <stdio.h>
int main()
{
    unsigned int a,b;

    printf("\nex3:\n");
    printf("input a hex number\n");
    scanf("%x",&a);
    b=a;

    b=(b<<24)>>31;
    printf("The seventh bit is %u\n",b);

    a=a|(1<<7);
    printf("result = 0x%x\n",a);

    return 0;
}