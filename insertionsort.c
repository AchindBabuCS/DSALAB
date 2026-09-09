#include <stdio.h>
int main()
{
	int i=0,j=0,k=0,n=0,temp=0;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter element: ");
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		int key=a[i];
		j=i-1;
		while(j>=0 && key<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	printf("Sorted array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
