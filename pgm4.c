#include <stdio.h>
int binarySearch(int arr[], int n, int x);
int main() {
    int n = 0, i = 0, x = 0;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    // Sort the array before performing binary search
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int result = binarySearch(arr, n, x);
    if (result != -1) {
        printf("The element %d is found at index %d.\n", x, result);
    } else {
        printf("The element %d is not found in the array.\n", x);
    }

    return 0;
}
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}