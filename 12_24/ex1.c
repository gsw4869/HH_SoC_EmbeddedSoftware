#include <stdio.h>
int main()
{
    char id[20];
    float grade;
    char name[20], gender[20];

    printf("ex1:\n");

    printf("input id\n");
    scanf("%s",id);

    printf("input name\n");
    scanf("%s",name);

    printf("input gender\n");
    scanf("%s",gender);
    while(strcmp(gender,"male")&&strcmp(gender,"female"))
    {
        printf("error,input gender(male,female)\n");
        scanf("%s",gender);
    }

    printf("input grade\n");
    scanf("%f",&grade);
    while(grade>100|grade<0)
    {
        printf("error,input grade(0-100)\n");
        scanf("%f",&grade);
    }

    printf(" id: %s  name:%s  gender: %s  grade: %.1f\n", id, name, gender, grade);
    return 0;
}