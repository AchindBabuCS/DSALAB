#include <stdio.h>
int main()
{
	int i=0,j=0,me=0,n=0,temp=0;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter element: ");
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		me=i;
		j=i+1;
		while(j<n)
		{
			if(a[me]>a[j])
			{
				me=j;
			}
			j++;
		}
		temp=a[i];
		a[i]=a[me];
		a[me]=temp;
	}
	printf("Sorted Array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
