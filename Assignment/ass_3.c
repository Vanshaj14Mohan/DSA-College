//Write a C program to implement matrix manipulation:
// 1. Transpose of a matrix
// 2. Multiplication of two matrices.

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
return 0;
}
