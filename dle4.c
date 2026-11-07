#include <stdio.h>
void merge(int arr[], int low, int mid, int high)
{
    int temp[high+1];
    int i=low, j=mid+1, k=low;
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(k=low;k<high+1;k++)
    {
        arr[k]=temp[k];
    }
    for(k=0;k<high+1;k++)
    {
        printf("%d, ",arr[k]);
    }
    printf("\n");
}
void mergeSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
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
    mergeSort(arr,0,n-1);
    printf("Sorted array: ");
    for(i=0;i<n;i++)
    {
        printf("%d, ",arr[i]);
    }
    return 0;
}