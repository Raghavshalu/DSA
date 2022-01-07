#include <stdio.h>
#include<stdbool.h>
void buble_sort(int a[],int);
int main()
{
    int n,temp,i;
    printf("enter the size ofan array:");
    scanf("%d",&n);
        int a[n];
        printf("enter the element of an array:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    bubble_sort(a,n);
}
   void bubble_sort(int a[],int n){
        int i,temp;
        bool flag;
       flag = false;
        while(flag==false){
            flag=true;
              for(i=0;i<n-1;i++)
              {
                if(a[i]>a[i+1]){
                 temp=a[i+1];
                 a[i+1]=a[i];
                 a[i]=temp;
                 flag=false;
                }
                }
            }
             printf("Sorted Array:");
           for(i = 0; i < n; i++)
           printf("%d\t", a[i]);
           printf("\n");
}