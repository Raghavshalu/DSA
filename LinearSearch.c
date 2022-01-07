#include<stdio.h>
int main(){
    int n,search,i;
    printf("enter the size of an array:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of an array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter element to be search:");
    scanf("%d",&search);
    for(i=0;i<n;i++){
    if(search==arr[i])
      {
          printf("element is found at index:%d",i);
          break;
      }
    }
    if(i==n)
    {
        printf("element is not found");
    }
}