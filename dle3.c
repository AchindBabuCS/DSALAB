#include <stdio.h>
int main()
{
    int n=0,i=0,j=0,temp=0;
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
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        printf("Pass %d: ",i);
        for(j=0;j<n;j++)
        {
            printf("%d, ",arr[j]);
        }
        printf("\n");
    }
    return 0;
}