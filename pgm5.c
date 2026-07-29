#include <stdio.h>
int main() {
    int i=0,j=0,k=0,n=0;
    printf("Enter no of elements in array 1: ");
    scanf("%d", &n);
    int arr1[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr1[i]);
    }
    printf("Enter no of elements in array 2: ");
    scanf("%d", &k);
    int arr2[k];
    for(i=0;i<k;i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr2[i]);
    }
    int arr3[n+k];
    i=j=0;
    for(int in=0;in<n+k;in++)
    {
        if(i<n && j<k)
        {
            if(arr1[i]<arr2[j])
            {
                arr3[in]=arr1[i];
                i++;
            }
            else
            {
                arr3[in]=arr2[j];
                j++;
            }
        }
        else if(i<n)
        {
            arr3[in]=arr1[i];
            i++;
        }
        else
        {
            arr3[in]=arr2[j];
            j++;
        }
    }
    printf("The merged array is: ");
    for(i=0;i<n+k;i++)
    {
        printf("%d ", arr3[i]);
    } 
    return 0;
}