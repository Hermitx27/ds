#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int g[MAX_VERTICES][MAX_VERTICES], visited[MAX_VERTICES], v;

void initGraph(int size) {
    v = size;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("Is there an edge between %d and %d? (1-yes/0-no): ", i, j);
            scanf("%d", &g[i][j]);
        }
        visited[i] = 0; // Initialize visited array to 0
    }
}

void dfs(int start) {
    visited[start] = 1; // Mark the current node as visited
    for (int i = 0; i < v; i++) {
        if (g[start][i] && !visited[i]) {
            printf("%d -> %d\n", start, i); // Print the edge
            dfs(i); // Recursive call for DFS
        }
    }
}

int main() {
    int size;
    printf("Enter the number of vertices: ");
    scanf("%d", &size);
    initGraph(size);
    printf("\nDFS traversal:\n");
    dfs(0); // Start DFS from vertex 0
    return 0; // Return success
}
