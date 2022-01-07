#include<stdio.h>
void selection_sort(int a[],int);
int main()
{
    int n;
    printf("enter the size of an array:");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements of an array:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    selection_sort(a,n);
}
void selection_sort(int a[],int n){
    int small;
    int pos;
    for(int i=0;i<n-1;i++){
        small=a[i];
        pos=i;
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                small=a[j];
                pos=j;
            }
        }
                int temp=a[i];
                 a[i]=a[pos];
                 a[pos]=temp;
    }
    printf("sorted array is:");
    for(int i=0;i<n;i++)
    printf("%d\t",a[i]);
}