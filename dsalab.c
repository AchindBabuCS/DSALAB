#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insertEnd(int x)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }  
        newnode->next=NULL;
        temp->next=newnode;
    }
}
void insertFront(int x)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        struct node *temp;
        temp=head;
        head=newnode;
        newnode->next=temp;
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
    }
    else
    {
        struct node *temp;
        temp=head;
        while(temp->data!=p)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void deleteFirst()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("list empty");
    }
    else
    {
        temp=head;
        head=temp->next;
        printf("%d is deleted\n",temp->data);
        free(temp);
    }
}
void deleteLast()
{
    struct node *temp1;
    struct node *temp2;
    if(head==NULL)
    {
        printf("List empty");
    }
    else
    {
        temp1=head;
        temp2=head->next;
        while(temp2->next!=NULL)
        {
            temp1=temp2;
            temp2=temp2->next;
        }
        temp1->next=NULL;
        printf("%d is deleted\n",temp2->data);
        free(temp2);
    }
}
void deleteBetween(int p)
{
    struct node *temp1;
    struct node *temp2;
    struct node *temp3;
    temp1=head;
    temp2=head->next;
    temp3=temp2->next;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        while(temp1!=NULL)
        {
            if(temp2->data==p)
            {
                break;
            }
            temp1=temp2;
            temp2=temp3;
            temp3=temp3->next;
        }
        temp1->next=temp3;
        printf("%d is deleted\n",temp2->data);
        free(temp2);
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
        else if(z==4)
        {
            deleteFirst();
        }
        else if(z==5)
        {
            deleteLast();
        }
        else if(z==6)
        {
            printf("Enter element which is to be deleted: ");
            scanf("%d",&m);
            deleteBetween(m);
        }
        else
        {
            printf("Error");
        }
        struct node *temp=head;
        while(temp!=NULL)
        {
            printf("%d,",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    return 0;
}