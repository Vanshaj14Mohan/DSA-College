// Implement linked list and it's operations:
// 1. Creation 
// 2. Insertion of a node 
// 3. Deletion of a node
// 4. Traversal

#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;           // Data of the node
    struct Node* next;  // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 1. Creation of Linked List (Head node)
struct Node* createLinkedList(int data) {
    return createNode(data);
}

// 2. Insertion of a Node at the end of the list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// 3. Deletion of a Node by value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == key) {
        *head = temp->next;  // Move head to the next node
        free(temp);  // Free the memory of the old head
        return;
    }

    struct Node* prev = NULL;

    // Search for the node to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the node wasn't found
    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);  // Free the memory
}

// 4. Traversal of the Linked List
void traverseLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // 1. Create linked list and insert nodes
    head = createLinkedList(10);  // Initial creation of list with one node
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);

    printf("Linked List after insertion:\n");
    traverseLinkedList(head);

    // 2. Deletion of a node
    printf("\nDeleting node with data 20:\n");
    deleteNode(&head, 20);
    traverseLinkedList(head);

    // 3. Deleting a node (head node)
    printf("\nDeleting node with data 10 (head node):\n");
    deleteNode(&head, 10);
    traverseLinkedList(head);

    // 4. Try deleting a non-existing node
    printf("\nTrying to delete a non-existing node with data 100:\n");
    deleteNode(&head, 100);
    traverseLinkedList(head);

    // Final linked list
    printf("\nFinal Linked List:\n");
    traverseLinkedList(head);

    return 0;
}
