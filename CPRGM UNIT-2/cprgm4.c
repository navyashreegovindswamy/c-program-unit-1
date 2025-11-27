#include<stdio.h>
void display(int arr[], int n)
{
    int i;
     printf("Array elements: ");
    for(i=0;i<n;i++)
     printf("%d ",arr[i]);   
}
int main()
{
int arr[5]={5,10,15,20,25};
display(arr,5);
return 0;
}