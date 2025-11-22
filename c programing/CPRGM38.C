#include<stdio.h>
int main()
{
    int a, b;
    printf("enter two numbers: ");
    scanf("%d %d", &a, &b);
    if(a > b)
    
        printf("%d is greater  \n", a);
    else
        printf("%d is greater  \n", b);
    
    return 0;
}