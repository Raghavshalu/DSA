#include <stdio.h>
#include<math.h>
// int heap_size;
void bulid_heap(int a[],int heap_size);
void heap_sort(int a[],int heap_size);
void heapify(int a[],int n,int i);
void printArr(int a[],int n) ;
// int length();
int main()
{
    int heap_size;
    printf("\nEnter Elements : \n");
    scanf("%d",&heap_size);
    int a[100];
    printf("array of an elements:\n");
        for(int i=1;i<=heap_size;i++){
        scanf("%d",&a[i]);}
    printf("Before sorting array elements are - \n");  
    printArr(a,heap_size);  
    heap_sort(a,heap_size);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a,heap_size);  
    return 0;  
}
void printArr(int a[],int n)  
{  
	int i;
    for ( i=1;i<=n; ++i)  
    {  
        printf("%d",a[i]);  
        printf(" ");  
    } 
}  
// int length(){
//     return heap_size;
// }
void bulid_heap(int a[],int heap_size){
    // heap_size=length();
    for(int i=floor(heap_size/2);i>=1;i--){
        heapify(a,heap_size,i);
    }
}
void heapify(int a[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && a[left]>a[largest]){
        largest=left;
    }
    else{
        largest=i;
    }
    if(right<=n && a[right]>a[largest]){
        largest=right;
    }
    if(largest!=i){
        int temp;
        temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
    heapify(a,n,largest);
    }
}
void heap_sort(int a[],int heap_size){
    bulid_heap(a,heap_size);
    // int len=length();
    for(int i=heap_size;i>=1;i--){
        int temp;
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        heap_size=heap_size-1;
        heapify(a,heap_size,1);
    }
}
