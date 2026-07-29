#include <stdio.h>
int main() {
    int i=0,j=0,temp=0,x=0,n=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("enter element to be removed: ");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            for(j=i;j<n-1;j++)
            {
                arr[j]=arr[j+1];
            }
            n--;
            i--;
        }
    }
    printf("Array after removing the element: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}