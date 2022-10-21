#include<stdio.h>
#include<stdlib.h>
// Fuction to create a graph with n vertices
int** createGraph(int n) {
    int **graph = (int**)malloc(n * sizeof(int*));
    for (int i = 1; i <= n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = 0;
        }
    }
    return graph;
}
// Function to add an edge to the graph
void addEdge(int **graph, int u, int v) {
    graph[u][v] = 1;
}
// Function to print the graph
void printGraph(int **graph, int n) {
    int i, j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n = 5;
    int **graph = createGraph(n);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 1);
    addEdge(graph, 3, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 4, 5);
    printGraph(graph, n);
    return 0;
}