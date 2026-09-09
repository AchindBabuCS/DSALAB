#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void front(int x)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=head;
	head=newnode;
}
void end(int x)
{
	struct node *newnode, *temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void inbetween(int x, int pos)
{
	struct node *newnode, *temp;
	int i;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	temp=head;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
}
int main()
{
	int i,y,n,x,choice,pos;
	printf("enter no of nodes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		end(x);
	}
	printf("Linked List is");
	display();
	y=0;
	printf("Insert-1:Front;2-Inbetween;3-End;4-Exit");
	while(y<1)
	{
		display();
		printf("Enter choice: ");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter element: ");
			scanf("%d",&x);
			front(x);
		}
		else if(choice==2)
		{
			printf("Enter element: ");
			scanf("%d",&x);
			printf("Enter position: ");
			scanf("%d",&pos);
			inbetween(x, pos);
		}
		else if(choice==3)
		{
			printf("Enter element: ");
			scanf("%d",&x);
			end(x);
		}else if(choice==4)
		{
			break;
		}
	}
	return 0;
}
