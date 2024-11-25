//Write a C program for infix expression to postfix conversion using Stack. 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, char item) {
    if (s->top < MAX - 1) s->items[++(s->top)] = item;
}

char pop(Stack* s) {
    return isEmpty(s) ? '\0' : s->items[(s->top)--];
}

char peek(Stack* s) {
    return isEmpty(s) ? '\0' : s->items[s->top];
}

int precedence(char op) {
    return (op == '+' || op == '-') ? 1 : (op == '*' || op == '/') ? 2 : 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack* stack = createStack();
    int i = 0, j = 0;

    while (infix[i]) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[j++] = pop(stack);
            pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i]))
                postfix[j++] = pop(stack);
            push(stack, infix[i]);
        }
        i++;
    }
    while (!isEmpty(stack))
        postfix[j++] = pop(stack);
    postfix[j] = '\0';
    free(stack);
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
