#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;	
};
void insert();
void insert_beg();
void insert_end();
void insert_specific();
void delete_beg();
void delete_specific();
void delete_end();
void display();
struct node *head=NULL,*traverse=NULL,*newnode=NULL;
int n;
int main()
{
	int ch,choice;
	int a,b;
	insert();
	display();
    printf("\nDo you want to insert new node somewhere in between,end,beginning:\n1. Yes\n0. No\n");
	scanf("%d",&a);
	while(a){
		printf("\n 1.insert at starting\n2.insert at specific location\n3.insert at end\nchoose option");
		scanf("%d",&ch);
		switch (ch)
		{
		case 1:insert_beg();
			break;
		case 2:insert_specific();
			break;
		case 3:insert_end();
			break;
		default:printf("\ndefault choice\t");
			break;
	}
	printf("\nDo you want to insert new node :\n1. Yes\n0. No\n");
	scanf("%d",&a);
	}
	display();
	printf("\nDo you want to delete node somewhere in between,end,beginning:\n1. Yes\n0. No\n");
	scanf("%d",&b);
	while(b){
		printf("\n 1.delete at starting\n2.delete at specific location\n3.delete at end\nchoose option");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:delete_beg();
			break;
		case 2:delete_specific();
			break;
		case 3:delete_end();

			break;
		default:printf("\ndefault choice\t");
			break;
	}
	printf("\nDo you want to delete node :\n1. Yes\n0. No\n");
	scanf("%d",&b);
	}
	display();
}
void insert(){
	do{
	newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("\nNO memory allocated");
		}
		else
		{
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nenter the data to be inserted in newnode:");
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
			traverse=newnode;
			}	
			traverse->next=head;	
		}	
		printf("\nDo you want to insert new node :\n1. Yes\n0. No\n");
	scanf("%d",&n);
	}while(n);
}
void display(){
	traverse=head;
	if(head==NULL){
		printf("\nempty");
	}
	else{
		while(traverse->next!=head){
			printf("%d,",traverse->data);
			traverse=traverse->next;
		}
		printf("%d,",traverse->data);
	}
}
void insert_beg(){
  struct node* ptr=head;
	newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nenter the data to be inserted:");
            scanf("%d",&newnode->data);
            newnode->next=NULL;
            printf("\ndata inserted:%d",newnode->data);
	while(ptr->next!=head){
        ptr=ptr->next;
    }
	//at this point ptr points to last node 
			if(head==NULL){
				head=newnode;
				newnode->next=head;
				ptr=head;
			}
			else{
				newnode->next=head;
				ptr->next=newnode;
				head=ptr->next;
			}
}
void insert_end(){
   traverse=head;
    while(traverse->next!=head){
        traverse=traverse->next;
    }
    struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nenter the data to be inserted:");
            scanf("%d",&newnode->data);
            newnode->next=NULL;
            printf("\ndata inserted:%d",newnode->data);
    if(head==NULL){
				head=newnode;
				newnode->next=head;
	}
	else{
	traverse->next=newnode;
	newnode->next=head;
	}
	traverse=newnode;
}
void insert_specific(){
	int loc,count=1;
	printf("enter the location for insert an element:");
	scanf("%d",&loc);
			newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nenter the data to be inserted:");
            scanf("%d",&newnode->data);
            newnode->next=NULL;
            printf("\ndata inserted:%d",newnode->data);
	if(head==NULL){
		head=newnode;
		newnode->next=head;
		traverse=newnode;
	}
	else{
		traverse=head;
		while(count!=loc){
			traverse=traverse->next;
			count++;
		}
	}
	newnode->next=traverse->next;
	traverse->next=newnode;
}
void delete_beg(){
    if(head==NULL)
	{
	printf("deletion not possible");
	}
	else
	{
		while(traverse->next!=head){
        traverse=traverse->next;
    	}
	struct node*ptr=head;
	head=head->next;
	printf("data of deleted node %d",ptr->data);
	free(ptr);
	traverse->next=head;
	}
}
void delete_specific(){
	struct node *ptr;
	int count=1,loc;
	printf("\nenter the location of node that you want to delete");
	scanf("%d",&loc);
    traverse=head;
    while(traverse->next!=head &&count!=loc)
    {
    	ptr=traverse;
    	traverse=traverse->next;
    	count++;
	}
    ptr->next=traverse->next;
    printf("data of deleted node %d",traverse->data);
    free(traverse);
}
void delete_end(){
	traverse=head;
	struct node*ptr=head;
    while(traverse->next!=head){
        ptr=traverse;
        traverse=traverse->next;
    }
    ptr->next=head;
	printf("data of deleted node %d",traverse->data);
    free(traverse);
}