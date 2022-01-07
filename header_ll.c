#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;	
};
struct node *head=NULL,*traverse=NULL,*newnode=NULL,*ptr;
void insert();
void display();
void header();
int isPrime(int n);
int main()
{
	insert();
    display();
    header();
    display();
}
void insert()
{
		int a;
	do{
	newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("\nNO memory allocated");
		}
		else
		{
			newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nenter the data to be inserted:");
            scanf("%d",&newnode->data);
            newnode->next=NULL;
            printf("\ndata inserted:%d",newnode->data);
			if(head==NULL)
			{
				head=newnode;	
				traverse=head;
			}
				else
			{
            traverse->next=newnode;
            traverse=traverse->next;
			}		
		}	
		printf("\nDo you want to insert new node :\n1. Yes\n0. No\n");
	    scanf("%d",&a);
	}while(a);
}
void display()
{
	traverse=head;
    printf("\ndisplaying all elements:");
	if(traverse==NULL){
		printf("\nempty");
	}
    while(traverse!=NULL){
        printf("%d,",traverse->data);
        traverse=traverse->next;
    }
}
void header(){
    traverse=head;
    int c=0;
    newnode=(struct node*)malloc(sizeof(struct node));
        if(head==NULL){
            newnode->data=0;
            newnode->next=NULL;
            printf("\nData of header:%d",newnode->data);
        }
        else{
            while (traverse!=NULL)
            {
                if(isPrime(traverse->data)) {
                c++;
                }
                traverse=traverse->next;
            }
            newnode->data=c;
            newnode->next=head;
            head=newnode;
            printf("\nData of header:%d",newnode->data);
        }
}
int isPrime(int n)
{
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 0;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}