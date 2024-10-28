//Write a program to reverse an array.
#include<stdio.h>
int main(){
    int arr[50];
    int n, i ;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    //Checking condition
    if(n>50 || n<=0){
        printf("Wrong input, enter elements again");
        return 1;
    }
    //for array element
    printf("Enter %d elements: \n", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    //for reverse order
    printf("For reverse order: \n");
    for(i = n-1; i>=0; i--){
        printf("%d\n", arr[i]);
    }
    return 0;
}
