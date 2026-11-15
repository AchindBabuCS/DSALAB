#include <stdio.h>
void heapify(int arr[], int n, int i)
{
    int largest=i;
    int left=(2*i)+1;
    int right=(2*i)+2;
    if(n>left && arr[left]>arr[largest])
    {
        largest=left;
    }
    if(n>right && arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr, n, largest);
    }
}
void buildHeap(int arr[], int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify(arr, n, i);
    }
}
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    int k=1;
    for(int i=n-1;i>0;i--)
    {
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,i,0);
        printf("Pass %d: ",k++);
        for(int j=0;j<n;j++)
        {
            printf("%d, ",arr[j]);
        }
        printf("\n");
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
    heapSort(arr, n);
    return 0;
}