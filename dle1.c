#include <stdio.h>
int main()
{
    int n=0,i=0,j=0,k=0,key=0;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    printf("\n");
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && key<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        printf("Pass %d: ",i);
        for(k=0;k<n;k++)
        {
            printf("%d, ",arr[k]);
        }
        printf("\n");
    }
    return 0;
}