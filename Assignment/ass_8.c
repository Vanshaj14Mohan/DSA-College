// Write a program for quick sort
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] <= pivot)
            swap(&arr[++i], &arr[j]);
    swap(&arr[i + 1], &arr[high]);  // Ensure the pivot goes to the correct position
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Get pivot index
        quick_sort(arr, low, pi - 1);  // Sort left subarray
        quick_sort(arr, pi + 1, high);  // Sort right subarray
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, n - 1);
    print_array(arr, n);
    return 0;
}
