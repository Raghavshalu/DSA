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
void insert_beg();
void insert_specific();
void insert_end();
void search();
void delete_beg();
void delete_specific();
void delete_end();
void reverse();
int main()
{
	int ch,choice;
	int a,b;
	insert();
    display();
	search();
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
	search();
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
	reverse();
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
void insert_beg(){
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nenter the data to be inserted:");
            scanf("%d",&newnode->data);
            newnode->next=NULL;
            printf("\ndata inserted:%d",newnode->data);
			if(head==NULL){
				head=newnode;
			}
			else{
				newnode->next=head;
				head=newnode;
			}
}
void insert_end(){
    traverse=head;
    while(traverse->next!=NULL){
        traverse=traverse->next;
    }
    struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nenter the data to be inserted:");
            scanf("%d",&newnode->data);
            newnode->next=NULL;
            printf("\ndata inserted:%d",newnode->data);
    traverse->next=newnode;
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
	ptr=head;
	head=head->next;
	printf("data of deleted node %d",ptr->data);
	free(ptr);
	}
}
void delete_specific(){
    struct node *ptr;
	int count=1,loc;
	printf("\nenter the location of node that you want to delete");
	scanf("%d",&loc);
    traverse=head;
    while(traverse->next!=NULL&&count!=loc)
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
    traverse=ptr=head;
    while(traverse->next!=NULL){
        ptr=traverse;
        traverse=traverse->next;
    }
    ptr->next=NULL;
	printf("data of deleted node %d",traverse->data);
    free(traverse);
}
void search(){
    int s,flag=0,c=1;
	traverse=head;
    printf("\nenter element to be search:");
    scanf("%d",&s);
    while(traverse->next!=NULL){
        if(traverse->data==s){
            flag=1;
			break;
        }
        else{
            traverse=traverse->next;
        }
        c++;
    }
   if(flag==0)
	printf("\nelement not found");
	else if(flag==1)
	printf("\nelement present at node %d",c);
}
void reverse(){
	struct node* prevnode,*curnode;
	prevnode=curnode=head;
	if(head!=NULL){
		head=head->next;
		curnode=head;
		prevnode->next=NULL;
		while(head!=NULL){
			head=head->next;
			curnode->next=prevnode;
			prevnode=curnode;
			curnode=head;
		}
		head=prevnode;
	}

}