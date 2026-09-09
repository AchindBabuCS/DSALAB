#include <stdio.h>
int top=-1;
int max=4;
int st[5];
void push(int x);
int pop();
int peek();
int main()
{
	int i=0,j=0,k=0;
	while(k==0)
	{
		printf("Enter option to excecute: ");
		printf("1:push 2:pop 3:peek 4:exit");
		scanf("%d",&i);
		if(i==1)
		{
			printf("enter element:");
			scanf("%d",&j);
			push(j);
		}
		else if(i==2)
		{
			int g=pop();
			if(g==-1)
			{
				printf("Stack underflow \n");
			}
			else
			{
				printf("%d \n",g);
			}
		}
		else if(i==3)
		{
			printf("%d \n",peek());
		}
		else
		{
			break;
		}
	}
}
void push(int x)
{
	if(top==max)
	{
		printf("Stack Overflow");
	}
	else
	{
		top++;
		st[top]=x;
		printf("%d pushed into stack \n",x);
	}
}
int pop()
{
	if(top==-1)
	{
		return -1;
	}
	else
	{
		int y=st[top];
		top--;
		return y;
	}
}
int peek()
{
	int z=st[top];
	return z;
}
