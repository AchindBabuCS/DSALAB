#include <stdio.h>
int main()
{
    int n=0,i=0;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    for(i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && key<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        printf("Pass %d: ",i);
        for(int k=0;k<=i;k++)
        {
            printf("%d, ",arr[k]);
        }
        printf("\n");
    }
}