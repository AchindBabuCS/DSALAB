#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *bst=NULL;
int nochild=0;
int onechild=0;
int twochild=0;
struct node *createNode(int x)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node *insertNode(int x, struct node *root)
{
    if(root==NULL)
    {
        return createNode(x);;
    }
    if(root->data<x)
    {
        root->right=insertNode(x, root->right);
    }
    else
    {
        root->left=insertNode(x, root->left);
    }
    return root;
}
void displayTree(struct node *root)
{
    while(root!=NULL)
    {
        displayTree(root->left);
        printf("%d, ",root->data);
        displayTree(root->right);
        break;
    }
}
void Traverse(struct node *root)
{
    if(root!=NULL)
    {
        Traverse(root->right);
        if(root->left==NULL && root->right==NULL)
        {
            nochild++;
        }else if((root->left==NULL && root->right!=NULL) ||  (root->left!=NULL && root->right==NULL))
        {
            onechild++;
        }else
        {
            twochild++;
        }
        Traverse(root->left);
    }
}
int main()
{
    int choice, element;
    printf("Enter 1 to insert element into BST\n");
    printf("Enter 2 to display BST\n");
    printf("Enter 3 to display nodes with 0,1,2 child nodes\n");
    printf("Enter 4 to exit\n");
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter element: ");
            scanf("%d",&element);
            bst=insertNode(element, bst);
        }
        else if(choice==2)
        {
            displayTree(bst);
            printf("\n");
        }
        else if(choice==3)
        {
            nochild=onechild=twochild=0;
            Traverse(bst);
            printf("No of nodes with 0 child nodes: %d\n",nochild);
            printf("No of nodes with 1 child nodes: %d\n",onechild);
            printf("No of nodes with 2 child nodes: %d\n",twochild);
        }
        else if(choice==4)
        {
            break;
        }
        else
        {
            printf("Invalid input. Try again\n");
        }
    }
    return 0;   
}