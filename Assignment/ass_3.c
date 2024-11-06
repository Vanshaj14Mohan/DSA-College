//Write a C program to implement matrix manipulation:
// 1. Transpose of a matrix
// 2. Multiplication of two matrices.

//For transpose
#include<stdio.h>
int main(){
    int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

int rows = 3;
int cols = 3;

printf("Original Array:\n");
for(int i =0; i<rows; i++){
    for(int j =0; j<cols; j++){
        printf("%d", arr[i][j]);
    }
    printf("\n");
}

//for transpose
int transpose[3][3];

for(int i =0; i<rows; i++){
    for(int j =0; j<cols; j++){
        transpose[j][i] = arr[i][j];
    }
}

printf("\nTransposed matrix:\n");
for(int i = 0; i<cols; i++){
    for(int j =0; j<rows;j++){
        printf("%d", transpose[i][j]);
    }
    printf("\n");
}

//For multiplication 
int secArr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
int res[3][3] = {0};

//multiply secArr with original array
for(int i =0; i<rows; i++){
    for(int j =0; j<cols; j++){
        for(int k =0; k<cols; k++){
            res[i][j] += arr[i][k] *secArr[k][j];
        }
    }
}

printf("\nResult for multiplication:\n");
for(int i =0; i<rows; i++){
    for(int j =0; j<cols; j++){
        printf("%d ", res[i][j]);
    }
    printf("\n");
}
return 0;
}

// #include <stdio.h>

// int main() {
//     // Define the first 3x3 array
//     int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int rows = 3;
//     int cols = 3;

//     // Print the original array
//     printf("Original Array:\n");
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }

//     // Compute the transpose
//     int transpose[3][3];
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             transpose[j][i] = arr[i][j];
//         }
//     }

//     // Print the transposed matrix
//     printf("\nTransposed matrix:\n");
//     for (int i = 0; i < cols; i++) {
//         for (int j = 0; j < rows; j++) {
//             printf("%d ", transpose[i][j]);
//         }
//         printf("\n");
//     }

//     // Define another 3x3 array for multiplication
//     int secondArr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // Identity matrix
//     int result[3][3] = {0}; // Initialize the result matrix to zero

//     // Multiply the original array with the second array
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             for (int k = 0; k < cols; k++) {
//                 result[i][j] += arr[i][k] * secondArr[k][j];
//             }
//         }
//     }

//     // Print the result of the multiplication
//     printf("\nResult of multiplication with the second array:\n");
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             printf("%d ", result[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }