#include <stdio.h>
void radixSort(int arr[], int n)
{
    int c=0,i=0,j=0,k=0,l=1,temp=0,max=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    while(max!=0)
    {
        c++;
        max=max/10;
    }
    for(i=1;i<=c;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n-j-1;k++)
            {
                if(((arr[k]/l)%10)>((arr[k+1]/l)%10))
                {
                    temp=arr[k];
                    arr[k]=arr[k+1];
                    arr[k+1]=temp;
                }
            }
        }
        printf("Pass %d: ",i);
        for(j=0;j<n;j++)
        {
            printf("%d, ",arr[j]);
        }
        printf("\n");
        l=l*10;
    }
}
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
    radixSort(arr,n);
    return 0;
}