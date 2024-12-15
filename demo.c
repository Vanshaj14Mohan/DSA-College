#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (!q->rear) q->front = newNode;
    else q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued: %d\n", data);
}

// Dequeue operation
void dequeue(Queue* q) {
    if (!q->front) {
        printf("Queue underflow.\n");
        return;
    }
    Node* temp = q->front;
    printf("Dequeued: %d\n", temp->data);
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
}

// Display queue
void displayQueue(Queue* q) {
    if (!q->front) {
        printf("Queue is empty.\n");
        return;
    }
    for (Node* temp = q->front; temp; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");
}

// Main function
int main() {
    Queue* q = createQueue();
    int choice, value;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    free(q);
    return 0;
}
