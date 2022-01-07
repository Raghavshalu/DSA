#include<stdio.h>
int push (int stack[], int item, int n);
int pop (int stack[]);
int peek(int stack[]);
int isempty(int stack[]);
int isfull(int stack[],int item,int n);
void display(int stack[],int);
int top =-1;
int main()
{ 
    int stack[10],n,item,x,ch,d,c;
    printf("\nEnter size of stack :");
    scanf("%d",&n);
    do{
       printf("1.Push\n");  
        printf("2.Pop\n");  
        printf("3.Peek\n");  
        printf("4.Display\n");  
        printf("Enter your choice : ");  
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value to inserted in stack :\n");
             scanf("%d",&item);
             push(stack,item,n);
            break;
        case 2:
                c=pop(stack);
                 printf("\nelement is pop is: %d\n",c); 
                 break;
        case 3:
                 d=peek(stack);
                printf("\nelement at uppermost position: %d\n",d);
                break;
        case 4:
                display(stack,n);
                break;
        default:
        printf("\ninvalid choice");
        } 
        printf("\npress 1 for yes 0 for no:");
        scanf("%d",&x);
    }while(x);
}
int push(int stack[10],int item,int n)
{ 
    if(!isfull(stack,item,n)){
        top=top+1;
        stack[top]=item;
        printf("\nitem pushed");
    }
}
int pop(int stack[])
{   
    int item;
    if(!isempty(stack)){
        item=stack[top];
        top=top-1;
        return item;
    }
}
int peek(int stack[]){
    int a=isempty(stack);
    if(a==0){
    return stack[top];
    }
}
int isempty(int stack[]){
    if(top==-1){
        printf("\nstack is empty");
        return 1;
    }else{
    return 0;
    }
}
int isfull(int stack[],int item,int n){
    if(top==n-1){
        printf("\nstack is full");
        return 1;
    }
    return 0;
}
void display(int stack[],int n){
    int i=top;
    if(isempty(stack)){
        printf("\nstack is empty");
    }
       else{ while(i>=0){
    printf("%d,",stack[i]);
    i--;}
    }
    
}