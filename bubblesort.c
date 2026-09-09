#include <stdio.h>
int main()
{
	int i=0,j=0,r=0,temp=0;
	printf("Enter no of elements: ");
	scanf("%d",&r);
	int a[r];
	for(i=0;i<r;i++)
	{
		printf("Enter element: ");
		scanf("%d",&a[i]);
	}
	for(i=0;i<r-1;i++)
	{
		for(j=0;j<r-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("Sorted array is:");
	for(i=0;i<r;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
