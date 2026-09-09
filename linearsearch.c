#include <stdio.h>
int main()
{
	int n=0,i=0,j=0;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter element: ");
		scanf("%d",&a[i]);
	}
	printf("Enter index of element to be found: ");
	scanf("%d",&j);
	for(i=0;i<n;i++)
	{
		if(i==(j-1))
		{
			printf("Element at %d is %d",j,a[i]);
		}
	}
	return 0;
}
