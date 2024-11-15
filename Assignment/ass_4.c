// Implement linked list and it's operations:
// 1. Creation 
// 2. Insertion of a node 
// 3. Deletion of a node
// 4. Traversal
//easy way

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node with specific data
void delete(struct Node** head, int data) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp->next && temp->next->data != data) temp = temp->next;
    if (temp->next) {
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}

// Function to traverse the list
void traverse(struct Node* head) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the linked list operations
int main() {
    struct Node* head = NULL;
    
    insert(&head, 10); 
    insert(&head, 20); 
    insert(&head, 30);
    insert(&head, 40);
    
    printf("List after insertion: ");
    traverse(head);
    
    delete(&head, 20);
    printf("List after deletion of 20: ");
    traverse(head);
    
    delete(&head, 10);
    printf("List after deletion of 10: ");
    traverse(head);
    
    return 0;
}
