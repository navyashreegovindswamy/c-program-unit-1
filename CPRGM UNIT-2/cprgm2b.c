#include<stdio.h>
#include<stdlib.h>
void insertionsort(int*arr1,int n)
{
    for(int i=0;i<n-1;i++)
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
    printf("\n******************\n interaction %d\n ******************\n",i+1);
    for(int k=0;k<n;k++)
        printf("%d ",arr1[k]);
    }
}
int main()
{
    int arr1[5]={34,7,23,32,5};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    printf("\n before sorting \n");
    for(int i=0;i<n;i++)
        printf("%d ",arr1[i]);
    insertionsort(arr1,n);
    printf("\n");
    printf("\n after sorting \n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr1[i]);
    return 0;
}
