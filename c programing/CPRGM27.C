#include<stdio.h>
int main()
{
    int a,b;
    printf("enter two numbers: ");
    scanf("%d %d",&a,&b);
    if (a>0)
{
        if (b>0)
        {
            printf("both numbers are positive\n");
        }
        else
        {
            printf("first number is positive and second number is not positive\n");
        }
    }
    else
    {
        if (b>0)
        {
            printf("first number is not positive and second number is positive\n");
        }
        else
        {
            printf("both numbers are not positive\n");
        }
    }
    return 0;
}
    