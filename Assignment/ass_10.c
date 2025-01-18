// Write a C program to Implement various operations of BST:
// 1. Searching
// 2. Insertion
// 3. Deletion (deletion of a node with no child, 1 child, 2 children).

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

// Search for a value in the BST
int search(struct Node* root, int key) {
    if (!root) return 0;
    if (key == root->data) return 1;
    return key < root->data ? search(root->left, key) : search(root->right, key);
}

// Find the minimum value node
struct Node* findMin(struct Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (!root) return NULL;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal of the BST
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                printf(search(root, value) ? "Found\n" : "Not Found\n");
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 4:
                printf("BST (Inorder): ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
