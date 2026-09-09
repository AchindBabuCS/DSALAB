#include <stdio.h>
int queue[5];
int max=5;
int front=0,rear=0;
void enqueue(int x);
void dequeue();
void display();	
int main()
{
	int x=0,y=0,z=0;
	printf("Enter choice-1:Enqueue;2-Dequeue;3-Display;4-Exit");
	while(x<1)
	{
		printf("Enter:");
		scanf("%d",&z);
		if(z==1)
		{
			printf("Enter element: ");
			scanf("%d",&y);
			enqueue(y);
		}
		else if(z==2)
		{
			dequeue();
		}else if(z==3)
		{
			display();
		}
		else if(z==4)
		{
			break;
		}
		else
		{
			printf("Wrong Input. Try Again");
		}
	}
}
void enqueue(int x)
{
	if((rear+1)%max==front)
	{
		printf("Queue OverFlow");
	}
	else
	{
		rear=(rear+1)%max;
		queue[rear]=x;
	}
}
void dequeue()
{
	if(front==rear)
	{
		printf("Queue Underflow");	
	}else
	{
		front=(front+1)%max;
		int y=queue[front];
		printf("%d is removed from queue",y);
	}
}
void display()
{
	int i=(front+1)%max;
	while(i!=(rear+1)%max)
	{
		printf("%d",queue[i]);
		i=(i+1)%max;
	}
}
