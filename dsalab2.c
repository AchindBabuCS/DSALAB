#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *last;
};
struct node *head=NULL;
void insertFront(int x)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        newnode->last=NULL;
    }
    else
    {
        struct node *temp;
        temp=head;
        head=newnode;
        newnode->next=temp;
        newnode->last=NULL;
        temp->last=newnode;
    }
}
void insertEnd(int x)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        newnode->last=NULL;
    }
    else
    {
        struct node *temp;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
        newnode->last=temp;
    }
}
void insertBetween(int x, int p)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        newnode->last=NULL;
    }
    else
    {
        struct node *temp;
        struct node *t;
        temp=head;
        while(temp!=NULL)
        {
            if(temp->data==p)
            {
                break;
            }
            temp=temp->next;
        }
        t=temp->next;
        temp->next=newnode;
        newnode->next=t;
        t->last=newnode;
        newnode->last=temp;
    }
}
int main()
{
    int x=0,y=0,z=0,m=0;
    printf("Enter 1 for insertion at front, 2 for insertion at back, 3 for insertion in between, 4 for deletion at front, 5 for deletion at back, 6 for deletion in between, 0 to exit\n");
    while(x<1)
    {
        printf("Enter position:");
        scanf("%d",&z);
        printf("Enter element: ");
        scanf("%d",&y);
        if(z==0)
        {
            printf("Exited");
            break;
        }
        else if(z==1)
        {
            insertFront(y);
        }
        else if(z==2)
        {
            insertEnd(y);
        }
        else if(z==3)
        {
            printf("Enter element after which new node is to be added:");
            scanf("%d",&m);
            insertBetween(y,m);
        }
        else
        {
            printf("Error");
        }
        struct node *temp=head;
        struct node *t;
        while(temp!=NULL)
        {
            printf("%d,",temp->data);
            t=temp;
            temp=temp->next;
        }
        printf("\n");
        temp=t;
        while(temp!=NULL)
        {
            printf("%d,",temp->data);
            temp=temp->last;
        }
        printf("\n");
    }
    return 0;
}