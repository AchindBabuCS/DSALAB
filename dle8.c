#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
int z=0;
struct node *createNode(int x)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void insertNode(int x, int y)
{
    struct node *newnode=createNode(x);
    newnode->data=x;
    if(head==NULL)
    {
        head=newnode;
        z++;
    }
    else if(y<2)
    {
        newnode->next=head;
        head=newnode;
        z++;
    }
    else
    {
        struct node *temp=head;
        int c=1;
        while(temp->next!=NULL)
        {
            if(c==(y-1))
            {
                break;
            }
            temp=temp->next;
            c++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        z++;
    }
}
int deleteNode(int x)
{
    int y=0;
    if(head==NULL)
    {
        printf("Empty List\n");
        return 0;
    }
    else if(head->next==NULL)
    {
        struct node *temp=head;
        head=NULL;
        y=temp->data;
        free(temp);
        return y;
    }
    else
    {
        if(x==1)
        {
            struct node *temp=head;
            head=head->next;
            y=temp->data;
            free(temp);
            z--;
            return y;
        }
        else
        {
            struct node *temp=head;
            int c=1;
            while(temp->next!=NULL)
            {
                if(c==(x-1))
                {
                    break;
                }
                temp=temp->next;
                c++;
            }
            struct node *temp2=temp->next;
            if(temp2->next==NULL)
            {
                temp->next=NULL;
                y=temp2->data;
                free(temp2);
                z--;
                return y;
            }
            else
            {
                temp->next=temp2->next;
                y=temp2->data;
                free(temp2);
                z--;
                return y;
            }
        }
    }
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d, ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int i=0,c=0,v=0;
    printf("Enter 1 to insert, 2 to display, 3 to delete, 4 to exit\n");
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d",&c);
        if(c==1)
        {
            printf("Enter element: ");
            scanf("%d",&v);
            if(z==0)
            {
                insertNode(v,1);
            }
            else
            {
                if(z==1)
                {
                    printf("Enter  to insert element at; 1 for beginning, 2 for end: ");
                }
                else
                {
                    printf("Enter  to insert element at; 1 for beginning, %d for end, or any position inbetween 1 and %d: ",z+1,z+1);
                }
                scanf("%d",&i);
                if(i==1)
                {
                    insertNode(v,1);
                }
                else{
                    insertNode(v,i);
                }
            }
        }
        else if(c==2)
        {
            display();
        }
        else if(c==3)
        {
            printf("Enter position of element to delete: ");
            scanf("%d",&i);
            if(z==1)
            {
                c=deleteNode(1);
                if(c!=0)
                {
                    printf("%d is deleted\n",c);
                }
            }
            else
            {
                c=deleteNode(i);
                if(c!=0)
                {
                    printf("%d is deleted\n",c);
                }
            }
        }
        else if(c==4)
        {
            printf("Exiting...");
            break;
        }
        else
        {
            printf("Invalid input. Try again");
        }
    }
}