//Find and display the duplicate array element.
#include <stdio.h>  
   
int main()  
{  
    int arr[] = {1,2,2,3,3,4,5,6,7,8,5,9,9,10,12,10};   
      
    int length = sizeof(arr)/sizeof(arr[0]);  
      
    printf("Duplicate elements in given array: \n");  
    for(int i = 0; i < length; i++) {  
        for(int j = i + 1; j < length; j++) {  
            if(arr[i] == arr[j])  
                printf("%d\n", arr[j]);  
        }  
    }  
    return 0;  
}