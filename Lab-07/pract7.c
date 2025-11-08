#include <stdio.h>

int adj[10][10];
int visited[10];
int n;

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v + 1);
    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (%dx%d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nEnter starting vertex (1 to %d): ", n);
    scanf("%d", &start);
    start--;

    printf("\nDFS Traversal starting from vertex %d:\n", start + 1);
    DFS(start);
    printf("\n");

    return 0;
}

