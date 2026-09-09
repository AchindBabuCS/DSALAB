#include <stdio.h>
int top=-1;
int max=19;
int st[20];
void push(int x);
int pop();
int main()
{
	int i=0,j=0,k=0;
	printf("enter length of expression: ")
	scanf("%d",&i);
	char ie[i];
	char pe[i];
	for(j=0;j<i;j++)
	{
		printf("	")
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
