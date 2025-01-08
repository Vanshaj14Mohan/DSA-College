//Write a program to Implement Linear Search and Binary Search
#include <stdio.h>

// Function for Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; //i means index here
        }
    }
    return -1; 
}

// Function for Binary Search
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) { //conditions
            return mid; 
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int choice, target, result;
    int arr[] = {2, 3, 4, 10, 40}; // Example sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Choose search method:\n1. Linear Search\n2. Binary Search\nEnter your choice (1 or 2): ");
    scanf("%d", &choice);
    printf("Enter the element to search: ");
    scanf("%d", &target);

    if (choice == 1) {
        result = linearSearch(arr, size, target);
    } else if (choice == 2) {
        result = binarySearch(arr, size, target);
    } else {
        printf("Invalid choice.\n");
        return 1; 
    }

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}