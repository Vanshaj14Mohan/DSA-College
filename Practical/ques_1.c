//Write a C program to find the whether a number is palindrome or not
#include <stdio.h>

int isPalindrome(int num) {
    int reversed = 0, original = num, remainder;

    while (num != 0) {
        remainder = num % 10;  // Get the last digit
        reversed = reversed * 10 + remainder;  // Build the reversed number
        num /= 10;  // Remove the last digit
    }

    return original == reversed;  // Check if original and reversed are the same
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);  // Read user input

    if (isPalindrome(number)) {
        printf("%d is a palindrome.\n", number);
    } else {
        printf("%d is not a palindrome.\n", number);
    }

    return 0;
}
