#include <stdio.h>
int binarysearch(int a[],int,int,int);
int main()
{
    int n, item,i;
    printf("\nEnter size of an array: ");
    scanf("%d", &n);
    int a[50];
    printf("\nEnter elements of an array in sorted form:\n");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    printf("\nEnter ITEM to be searched: ");
    scanf("%d", &item);
    int index=binarysearch(a,0,n-1,item);
    if(index == -1){
     printf("Element not found");
    }
   else{
     printf("Element is present at index %d",index);
    } 
   return 0;
}
int binarysearch(int a[],int beg,int end,int num)
{
    int mid = (beg + end) / 2;
    while (beg<=end)
    {
        if (a[mid] == num){
         return mid ;
         }
      else if(a[mid] > num){
         return binarysearch(a,beg, mid-1, num);
         }
      else if(a[mid] < num){
         return binarysearch(a, mid+1, end, num);
      }
   }
   return -1;
}