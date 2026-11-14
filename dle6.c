#include <stdio.h>
void heapify(int arr[], int n, int i)
{
    int largest=i;
    int left=(2*i)+1;
    int right=(2*i)+2;
    if(n>left && arr[largest]<arr[left])
    {
        largest=left;
    }
    if(n>right && arr[largest]<arr[right])
    {
        largest=right;
    }
    if(largest!=i)
    {
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
    }
    heapify(arr, n, largest);
}