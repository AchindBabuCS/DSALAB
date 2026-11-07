#include <stdio.h>
int main()
{
    int n=0, i=0, j=0, min=0,temp=0;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
        printf("Pass %d:",i+1);
        for(j=0;j<n;j++)
        {
            printf("%d, ",arr[j]);
        }
        printf("\n");
    }
    return 0;
}