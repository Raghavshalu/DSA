#include<stdio.h>
#include<ctype.h>
#define max 100
int top=-1;
char stack[max];
void push(char x);
char pop();
int isempty();
int isfull();
int priority(char x);
void push(char x)
{                          
    if(!isfull()){
        top++;
        stack[top]=x;
    }
}
char pop(){
    if(!isempty()){
       char value;
        value=stack[top];
        top--;
        return value;
    }
}
int isempty(){
    if(top==-1){
        printf("\nstack is empty");
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(){
    if(top=max-1){
        printf("\nstack is full");
        return 1;
    }
    else{
        return 0;
    }
}
int priority(char x){
    if(x=='^'){
       return 3;
       }
    else if(x=='*' || x=='/'){
        return 2;
    }
    else if(x=='+'||x=='-'){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    char ex[20];
    printf("enter the expression\n");
    scanf("%s",&ex);
    char e;
    char x;
    for(int i=0;i<'\0';i++)
    {
        e=ex[i];
        if(isalnum(ex[i]))
        {
        printf("%c",ex[i]);
        }
        else if(ex[i]=='('){
            push(ex[i]);
        }
       else if(ex[i]==')'){
            while((x=pop())!='(')
            printf("%c",x);
        }
        else{
            while(priority(stack[top])>=priority(ex[i])){
                printf("%c",pop());
            }
            push(ex[i]);
        }
        e++;
    }
    while(top!=-1){
        printf("%c",pop());
    }
}