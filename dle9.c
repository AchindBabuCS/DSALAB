#include <stdio.h>
#include <stdlib.h>
struct node{
    int exp;
    int coeff;
    struct node *next;
};
struct node *p1=NULL;
struct node *p2=NULL;
struct node *p3=NULL;
struct node *createNode(int x, int y)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->exp=x;
    newnode->coeff=y;
    newnode->next=NULL;
    return newnode;
}
void insertNode(struct node **p, int x, int y)
{
    struct node *newnode=createNode(x,y);
    if(*p==NULL)
    {
        *p=newnode;
    }
    else
    {
        struct node *temp=*p;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void display(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(temp->exp==0)
        {
            printf("%d",temp->coeff);
        }
        else
        {
            printf("%dx^%d",temp->coeff,temp->exp);
        }
        if(temp->next!=NULL)
        {
            printf("+");
        }
        temp=temp->next;
    }
}
void sum(struct node *p1, struct node *p2)
{
    struct node *i=p1;
    struct node *j=p2;
    while(i!=NULL && j!=NULL)
    {
        if(i->exp==j->exp)
        {
            insertNode(&p3,i->exp,(i->coeff+j->coeff));
            i=i->next;
            j=j->next;
        }
        else if(i->exp>j->exp)
        {
            insertNode(&p3,i->exp,i->coeff);
            i=i->next;
        }
        else
        {
            insertNode(&p3,j->exp,j->coeff);
            j=j->next;
        }
    }
    while(i!=NULL)
    {
        insertNode(&p3,i->exp,i->coeff);
        i=i->next;
    }
    while(j!=NULL)
    {
        insertNode(&p3,j->exp,j->coeff);
        j=j->next;
    }
}
int main()
{
    int n1=0,n2=0,i=0,x=0,y=0;
    printf("Enter no of elements of polynomial 1: ");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        printf("Enter exponent: ");
        scanf("%d",&x);
        printf("Enter coefficient: ");
        scanf("%d",&y);
        insertNode(&p1,x,y);
    }
    printf("Enter no of elements of polynomial 2: ");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        printf("Enter exponent: ");
        scanf("%d",&x);
        printf("Enter coefficient: ");
        scanf("%d",&y);
        insertNode(&p2,x,y);
    }
    printf("Polynomial 1: ");
    display(p1);
    printf("\n");
    printf("Polynomial 2: ");
    display(p2);
    printf("\n");
    sum(p1,p2);
    printf("Sum Polynomial: ");
    display(p3);
    printf("\n");
    return 0;
}