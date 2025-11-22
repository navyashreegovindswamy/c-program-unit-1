#include<stdio.h>
int main()
{
    int a,b;
    printf("enter two numbers: ");
    scanf("%d %d", &a, &b);
    if(a >0)
    {
        if(b >0)
        {
            printf("both numbers are positive\n");
        }
    }
    return 0;
}