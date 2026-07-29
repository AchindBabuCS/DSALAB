#include <stdio.h>
int main() {
    int n=0,x=0,j=0,i=0,temp=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be inserted: ");
    scanf("%d",&x);
    printf("Enter the position where the element is to be inserted: ");
    scanf("%d",&j);
    for(i=0;i<n;i++)
    {
        if(i==j-1)
        {
            temp=arr[i];
            arr[i]=x;
            for(int k=i+1;k<=n;k++)
            {
                int temp2=arr[k];
                arr[k]=temp;
                temp=temp2;
            }
        }
    }
    printf("The new array is: ");
    for(i=0;i<=n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}