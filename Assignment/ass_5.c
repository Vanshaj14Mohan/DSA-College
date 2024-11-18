// Write a code to perform push, pop and peek operations on Stack using switch cases.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

int stack[MAX], top = -1;

// Function to push an element onto the stack
void push() {
    int value;
    if (top == MAX - 1) {
        printf("Stack Overflow! Unable to push.\n");
        return;
    }
    printf("Enter the value to push: ");
    scanf("%d", &value);
    stack[++top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop an element from the stack5
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    printf("Popped %d from the stack.\n", stack[top--]);
}

// Function to peek at the top element of the stack
void peek() {
    if (top == -1) {
        printf("Stack is empty. Nothing to peek.\n");
        return;
    }
    printf("Top element is %d.\n", stack[top]);
}

// Function to display all elements of the stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

//main function
int main() {
    int choice;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
