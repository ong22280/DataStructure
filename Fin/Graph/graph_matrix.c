#include<stdio.h>

// Create the graph using adjacency-matrix representation
int** createGraph(int n) {
    // Return 2D array of size n*n
    int** adjMatrix = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = (int*)malloc(n*sizeof(int));
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    return adjMatrix;
}

// Delete the adjacency-matrix representation of the graph
void deleteGraph(int** adjMatrix, int n) {
    for (int i = 0; i < n; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
}

// Add the edge to the graph using adjacency-matrix representation
void addEdge(int** adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
}

// Remove the existing edge from the graph using adjacency-matrix representation
void removeEdge(int** adjMatrix, int u, int v) {
    adjMatrix[u][v] = 0;
}

// Print the adjacency-matrix representation of the graph
void printGraph(int** adjMatrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Add the new vertex to the graph using adjacency-matrix representation
int** addVertex(int** adjMatrix, int *n, int u) {
    int** adjMatrix_new = createGraph(u+1);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            adjMatrix_new[i][j] = 1;
        }
    }
    deleteGraph(adjMatrix, *n);
    *n = u+1;
    return adjMatrix_new;
}

// Remove the existing vertex from the graph using adjacency-matrix representation
int** removeVertex(int** adjMatrix, int *n, int u) {
    for (int i=0; i<*n; i++) {
        for (int j=u; j<*n-1; j++) {
            adjMatrix[i][j] = adjMatrix[i][j+1];
        }
    }
    for (int i=0; i<*n; i++) {
        for (int j=u; j<*n-1; j++) {
            adjMatrix[j][i] = adjMatrix[j+1][i];
        }
    }
    int **adjMatrix_new = createGraph(*n-1);
    for (int i=0; i<*n-1; i++) {
        for (int j=0; j<*n-1; j++) {
            adjMatrix_new[i][j] = adjMatrix[i][j];
        }
    }
    deleteGraph(adjMatrix, *n);
    (*n)--;
    return adjMatrix_new;
}

// Check whether the two vertices are adjacent using adjacency-matrix representation
int isAdjacent(int** adjMatrix, int u, int v) {
    if (adjMatrix[u][v] == 1) {
        return 1;
    } else {
        return 0;
    }
}

// Report the in-degree of the vertex using adjacency-matrix representation
int inDegree(int** adjMatrix, int n, int u) {
    int in_degree = 0;
    for (int i=0; i<n; i++) {
        if (adjMatrix[i][u] == 1) {
            in_degree++;
        }
    }
    return in_degree;
}

// Report the out-degree of the vertex using adjacency-matrix representation
int outDegree(int** adjMatrix, int n, int u) {
    int out_degree = 0;
    for (int i=0; i<n; i++) {
        if (adjMatrix[u][i] == 1) {
            out_degree++;
        }
    }
    return out_degree;
}

// Main function
int main() {
    int n = 5;
    int** adjMatrix = createGraph(n);
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 1);
    addEdge(adjMatrix, 2, 1);
    addEdge(adjMatrix, 4, 3);
    int in_degree = inDegree(adjMatrix, n, 3);
    printf("In-degree of vertex 3: %d\n", in_degree);
    int out_degree = outDegree(adjMatrix, n, 3);
    printf("Out-degree of vertex 3: %d\n", out_degree);
    return 0;
}