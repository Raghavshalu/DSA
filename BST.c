#include<stdio.h>
#include<stdlib.h>
struct node
{
   struct node *left,*right;
   int data;
};
struct node *insert(struct node*root,int item);
struct node *BST(struct node*root,int key);
struct node *find_parent(struct node*root,int key);
struct node* findsuccessor(struct node* searchdel);
void preorder(struct node*root);
void inorder(struct node*root);
void postorder(struct node*root);
void deletion(struct node*root);
int main(){
    int ch,item;
    struct node* root=NULL;
   do
   {
    printf("\nEnter the data:");
    scanf("%d",&item);
    root=insert(root,item);
    printf("\nPress 1 for more node otherwise 0:");
    scanf("%d",&ch);
    }while (ch); 
    printf("\nPreorder is:");
    preorder(root);
    printf("\nInorder is:");
    inorder(root);
    printf("\nPostorder is:");
    postorder(root);
    deletion(root);
    printf("\nAfter deletion Preorder is:");
    preorder(root);
    printf("\nAfter deletion Inorder is:");
    inorder(root);
    printf("\nAfter deletion Postorder is:");
    postorder(root);
    // int key;
    // printf("\nEnter the key which u have to search:");
    // scanf("%d",&key);
    // BST(root,key);
}
struct node *insert(struct node*root,int item){
    struct node* nn=NULL;
        if(root==NULL){
            nn=(struct node*)malloc(sizeof(struct node));
            nn->left=NULL;
            nn->right=NULL;
            nn->data=item;
            root=nn;
        }
        else
        {
            if(root->data>item){
                root->left=insert(root->left,item);
            }
            else if(root->data<item){
                root->right=insert(root->right,item);
            }
            else if(root->data==item){
                    printf("Not inserting same data");
                }
        }
        return root;
}
void preorder(struct node*root){
    if(root==NULL){
        return;
    }else{
    printf("%d,",root->data);
    preorder(root->left);
    preorder(root->right);}
}
void inorder(struct node*root){
    if(root==NULL){
        return;
    }else{
    inorder(root->left);
    printf("%d,",root->data);
    inorder(root->right);}
}
void postorder(struct node*root){
   if(root==NULL){
        return;
    }else{
    postorder(root->left);
    postorder(root->right);
    printf("%d,",root->data);}
}
struct node *BST(struct node*root,int key){
     int flag=0;
    // struct node*ptr=root;
    while (root!=NULL)
    {
    if(root->data==key){
        flag=1;
        break;
    }

    else if(root->data>key){
        root=root->left;
    }
    else{
        root=root->right;
    }
    }
    if(flag==1){
        //    printf("\n%d element is found",key);
           return root;
    }
    else{
        printf("\nelement is not found");
        return NULL;
    }
}
struct node *find_parent(struct node*root,int key){
    struct node*ptr=root;
    while (ptr!=NULL)
    {
    if(ptr->left->data==key || ptr->right->data==key){
                return ptr;
    }

    else if(ptr->data>key){
        ptr=ptr->left;
    }
    else if(ptr->data<key){
        ptr=ptr->right;
    }
    }
    // return -1;
}
void deletion(struct node*root){
    int search_del;
    struct node *parent;
    printf("\nEnter the key which u have to search:");
    scanf("%d",&search_del);
    struct node *searchdel=BST(root,search_del);
    printf("\nsearching element:%d",searchdel->data);
    if(searchdel==NULL){
        printf("\nelement is not found");
    }
    else{
    parent=find_parent(root,search_del);
    printf("\ndata of parent:%d",parent->data);
         //To delete a leaf node
         if(searchdel->left==NULL && searchdel->right==NULL){
             if(parent->left==searchdel){
                 parent->left=NULL;
                 free(searchdel);
             }
             else if(parent->right==searchdel){
                 parent->right=NULL;
                 free(searchdel);
             }
         }
         else
         //To delete a node having left hand child....
        if(searchdel->left!=NULL && searchdel->right==NULL){
              if(parent->left==searchdel){
                parent->left=searchdel->left;}
              else if(parent->right==searchdel){
                 parent->right=searchdel->left;}
            free(searchdel);
         }else
         //To delete a node having right hand child....
        if(searchdel->left==NULL && searchdel->right!=NULL){
            if(parent->right==searchdel){
                parent->right=searchdel->right;}
            else if(parent->left==searchdel){
                parent->left=searchdel->right;}
             free(searchdel);
         }else
         //To delete a node having both child/Internal node....
        if(searchdel->left!=NULL && searchdel->right!=NULL){
             struct node*succptr=findsuccessor(searchdel);
             printf("\nsuccessor:%d",succptr->data);
             struct node*parentsucc=find_parent(searchdel,succptr->data);
             printf("\nParent of successor:%d",parentsucc->data);
             searchdel->data=succptr->data;
             if(parentsucc!=searchdel){
             parentsucc->left=NULL;}
             else{
                  parentsucc->right=NULL;
             }
             free(succptr);
            }
         }
}
struct node* findsuccessor(struct node* searchdel){
    searchdel=searchdel->right;
    while(searchdel->left!=NULL){
        searchdel=searchdel->left;
    }
    return searchdel;
}