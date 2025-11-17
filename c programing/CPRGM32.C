#include<stdio.h>
int main()
{
    int n,i=1,sum=0;
    printf("enter a positive integer: ");
    scanf("%d",&n);
    do
    {
        sum += i;
        i++;
    }
    while(i<=n);
    printf("sum = %d",sum);
}