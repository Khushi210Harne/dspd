#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void KruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[V];
    struct Subset *subsets = (struct Subset*) malloc(V * sizeof(struct Subset));
    int e = 0, i = 0;
int v;
    for ( v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    qsort(edges, E, sizeof(struct Edge), compareEdges);

    while (e < V - 1 && i < E) {
        struct Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("\nEdges in the Minimum Spanning Tree (Kruskal's Algorithm):\n");
    int totalWeight = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src + 1, result[i].dest + 1, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight of MST = %d\n", totalWeight);

    free(subsets);
}

int main() {
    int V, E;
    printf("Enter number of nodes: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge *edges = (struct Edge*) malloc(E * sizeof(struct Edge));

    printf("Enter each edge as: source destination weight\n");
    int i;
	for ( i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges[i].src = u - 1;
        edges[i].dest = v - 1;
        edges[i].weight = w;
    }

    KruskalMST(edges, V, E);

    free(edges);
    return 0;
}

