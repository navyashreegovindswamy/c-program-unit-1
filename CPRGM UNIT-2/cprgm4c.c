#include<stdio.h>
int main()
{
    int arr[]={5,10,15,20,25};
    int *ptr = arr;
    printf("ptr=%p,*ptr=%d\n", ptr, *ptr);
    ptr++;
    printf(" after ptr=%p,*ptr=%d\n", ptr, *ptr);
    ptr+=2;
    printf(" after ptr=%p,*ptr=%d\n", ptr, *ptr);
    return 0;
}
    