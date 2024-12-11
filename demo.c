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



// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure of a Node
// typedef struct Node {
//     int data;
//     struct Node* next;
// } Node;

// // Define the structure of a Queue
// typedef struct Queue {
//     Node* front;
//     Node* rear;
// } Queue;

// // Function to create a new node
// Node* createNode(int data) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     if (!newNode) {
//         printf("Memory allocation failed.\n");
//         exit(1);
//     }
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to initialize an empty queue
// Queue* createQueue() {
//     Queue* q = (Queue*)malloc(sizeof(Queue));
//     if (!q) {
//         printf("Memory allocation failed.\n");
//         exit(1);
//     }
//     q->front = q->rear = NULL;
//     return q;
// }

// // Function to enqueue an element into the queue
// void enqueue(Queue* q, int data) {
//     Node* newNode = createNode(data);
//     if (q->rear == NULL) { // If the queue is empty
//         q->front = q->rear = newNode;
//         return;
//     }
//     q->rear->next = newNode;
//     q->rear = newNode;
//     printf("Enqueued: %d\n", data);
// }

// // Function to dequeue an element from the queue
// int dequeue(Queue* q) {
//     if (q->front == NULL) { // If the queue is empty
//         printf("Queue underflow.\n");
//         return -1;
//     }
//     Node* temp = q->front;
//     int data = temp->data;
//     q->front = q->front->next; // Move the front pointer
//     if (q->front == NULL) // If the queue becomes empty
//         q->rear = NULL;
//     free(temp);
//     printf("Dequeued: %d\n", data);
//     return data;
// }

// // Function to display the queue
// void displayQueue(Queue* q) {
//     if (q->front == NULL) {
//         printf("Queue is empty.\n");
//         return;
//     }
//     Node* temp = q->front;
//     printf("Queue elements: ");
//     while (temp) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// // Main function
// int main() {
//     Queue* q = createQueue();
//     int choice, value;

//     do {
//         printf("\nQueue Operations:\n");
//         printf("1. Enqueue\n");
//         printf("2. Dequeue\n");
//         printf("3. Display\n");
//         printf("4. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter value to enqueue: ");
//                 scanf("%d", &value);
//                 enqueue(q, value);
//                 break;
//             case 2:
//                 dequeue(q);
//                 break;
//             case 3:
//                 displayQueue(q);
//                 break;
//             case 4:
//                 printf("Exiting program.\n");
//                 break;
//             default:
//                 printf("Invalid choice. Please try again.\n");
//         }
//     } while (choice != 4);

//     // Free the memory used by the queue
//     while (q->front != NULL) {
//         dequeue(q);
//     }
//     free(q);

//     return 0;
// }