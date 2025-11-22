#include<stdio.h>
int main()
{
    int n,i;
    int fact =1;
    printf("enter a nymber");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    printf("factorial of %d is %d\n",n,fact);
    return 0;
}
