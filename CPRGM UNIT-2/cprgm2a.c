#include<stdio.h>
#include<stdlib.h>
void iinsertionsort(int*arr1,int n)
{
    for(int i=0;i<n;i++)
    {
       if(arr1[i]>arr1[i+1])
       for(int j=i+1;j>0;j--)
         {
              if(arr1[j]<arr1[j-1])
              {
                int temp=arr1[j];
                arr1[j]=arr1[j-1];
                arr1[j-1]=temp;
              }
    }
    printf("\n******************\n interatction %d\n ******************\n",i+1);
    for(int k=0;k<n;k++)
        printf("%d ",arr1[k]);
    }
}
int main()
{
    int arr1[5]={25,12,22,64,11};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    printf("\n before sorting \n");
    for(int i=0;i<n;i++)
        printf("%d ",arr1[i]);
    iinsertionsort(arr1,n);
    printf("\n");
    printf("\n after sorting \n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr1[i]);
    return 0;
}