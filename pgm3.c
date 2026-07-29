#include <stdio.h>
int main() {
    int n=0,i=0,c=0,x=0;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            c++;
        }
    }
    printf("The element %d occurs %d times in the array.", x, c);
    return 0;
}