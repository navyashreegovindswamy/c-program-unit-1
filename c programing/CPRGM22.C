#include<stdio.h>
int main()
{
    int a = 5, b = 10;
    printf("result1:%d\n",(a<b) && (b>0));
    printf("result2:%d\n",(a>b) ||(b>0));
    printf("result3:%d\n",!(a==b));
    return 0;
}