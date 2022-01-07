#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *create();
void inorder_traversal(struct node *root);
void preorder_traversal(struct node *root);
void postorder_traversal(struct node *root);
int main()
{
	struct node *root=NULL,*element;
	int ch,again,key;
	do
	{
		printf("1.create  2.inorder_traversal 3.preorder_traversal  4.postorder_traversal \n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:root=create();
			       break;
			case 2:inorder_traversal(root);
			       break;
			case 3:preorder_traversal(root);
			       break;	
			case 4:postorder_traversal(root);
			       break;   
			default:printf("invalid choice");
			       break;	   	             
		}
	printf("\nDo you want to perform more operation\n");
	printf("Press 1.yes 0.No");	
	scanf("%d",&again);
	}
	while(again);

}
struct node *create()
{
    struct node *newnode;
    int choice;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter Data");
	scanf("%d",&newnode->data);
	newnode->left=NULL;
	newnode->right=NULL;
	printf("Does %d have left node Press 1.yes 0.No",newnode->data);
	scanf("%d",&choice);
	if(choice)
	{
		newnode->left=create();
	}
	printf("Does %d have right node Press 1.yes 0.No",newnode->data);
	scanf("%d",&choice);
	if(choice)
	{
		newnode->right=create();
	}
	return newnode;
}
void inorder_traversal(struct node *root)
{
    if(root==NULL)
	{
		return;
	}
	else
	{
		inorder_traversal(root->left);
		printf("%d ",root->data);
		inorder_traversal(root->right);
	}	
}
void preorder_traversal(struct node *root)
{
    if(root==NULL)
	{
		return;
	}
	else
	{
		printf("%d ",root->data);
		preorder_traversal(root->left);
	    preorder_traversal(root->right);
	}	
}
void postorder_traversal(struct node *root)
{
    if(root==NULL)
	{
		return;
	}
	else
	{
		postorder_traversal(root->left);
		postorder_traversal(root->right);
		printf("%d ",root->data);
	}	
}