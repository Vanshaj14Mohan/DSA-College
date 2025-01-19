#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX]; // Adjacency matrix representation of the graph
int visited[MAX];        // Array to keep track of visited nodes
int queue[MAX];          // Queue for BFS
int front = -1, rear = -1;

// Function to add an edge to the graph
void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // For an undirected graph
}

// Breadth-First Search (BFS)
void BFS(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0; // Initialize visited array
    front = rear = -1; // Initialize queue
    queue[++rear] = start;
    visited[start] = 1;
    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);
        for (int i = 0; i < n; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Depth-First Search (DFS)
void DFSUtil(int current, int n) {
    visited[current] = 1;
    printf("%d ", current);
    for (int i = 0; i < n; i++) {
        if (adjMatrix[current][i] == 1 && !visited[i]) {
            DFSUtil(i, n);
        }
    }
}

void DFS(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0; // Initialize visited array
    DFSUtil(start, n);
    printf("\n");
}

int main() {
    int n, e, u, v, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &start);
    BFS(start, n);
    DFS(start, n);
    return 0;
}
