#include <stdio.h>
int main()
{
	int i=0,j=0,k=0,l=0,m=0,o=0,x1=0,y1=0,z1=0,x2=0,y2=0,z2=0;
	printf("Enter no of rows of matrix 1: ");
	scanf("%d",&x1);
	printf("Enter no of columns of matrix 1: ");
	scanf("%d",&y1);
	printf("Enter no of non-zero elements of matrix 1: ");
	scanf("%d",&z1);
	printf("Enter no of rows of matrix 2: ");
	scanf("%d",&x2);
	printf("Enter no of columns of matrix 2: ");
	scanf("%d",&y2);
	printf("Enter no of non-zero elements of matrix 2: ");
	scanf("%d",&z2);
	S1[z1+1][3];
	S2[z2+1][3];
	for(i=1;i<=z1;i++)
	{
		printf("Enter row of non-element of matrix 1: ");
		scanf("%d",&S1[i][0]);
		printf("Enter column of non-element of matrix 1: ");
		scanf("%d",&S1[i][1]);
		printf("Enter non-zero element of matrix 1: ");
		scanf("%d",&S1[i][2]);
	}
	for(i=1;i<=z2;i++)
	{
		printf("Enter row of non-element of matrix 2: ");
		scanf("%d",&S2[i][0]);
		printf("Enter column of non-element of matrix 2: ");
		scanf("%d",&S2[i][1]);
		printf("Enter non-zero element of matrix 2: ");
		scanf("%d",&S2[i][2]);
	}
	for(i=0;i<=z1;i++)
	{
		printf("%d %d %d\n",S1[i][0],S1[i][1],S1[i][2]);
	}
	for(i=0;i<=z2;i++)
	{
		printf("%d %d %d\n",S2[i][0],S2[i][1],S2[i][2]);
	}
	
}
