#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10
int graph[MAX_VERTICES][MAX_VERTICES], visited[MAX_VERTICES];
int queue[MAX_VERTICES], front = 0, rear = -1;
int vertices, i , j;
void initGraph(int size) {
    vertices = size;
    for ( i = 0; i < vertices; i++) {
	for ( j = 0; j < vertices; j++) {
            printf("Is there an edge between %d and %d? (1-yes/0-no): ", i, j);
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0; // Initialize visited array
    }
}
void bfs(int start) {
    printf("%d ", start); // Print the current node
    visited[start] = 1; // Mark the starting node as visited
    queue[++rear] = start; // Enqueue the starting node
    while (front <= rear) {
	int current = queue[front++], i; // Dequeue the front node
	// Check all adjacent nodes
	for ( i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark as visited
                queue[++rear] = i; // Enqueue the adjacent node
                printf("%d ", i); // Print the adjacent node
            }
        }
    }
}
int main() {
    int size;
    printf("Enter the number of vertices: ");
    scanf("%d", &size);
    initGraph(size); // Initialize graph
    printf("BFS traversal: ");
    bfs(0); // Start BFS from vertex 0
    return 0;
}
