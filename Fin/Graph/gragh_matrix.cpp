#include <iostream>
using namespace std;

// createGraph
int** createGraph(int n) {
    int** adjMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = new int[n];
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = 0;
    }
    return adjMatrix;
}

// printGraph
void printGraph(int** adjMatrix, int n) {
    for (int i = 0; i < n; i++) {
        cout << "[" << i << "] ";
        for (int j = 0; j < n; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

// addEdge
void addEdge(int** adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

// removeEdge
void removeEdge(int** adjMatrix, int u, int v) {
    adjMatrix[u][v] = 0;
    adjMatrix[v][u] = 0;
}

// addVertex
void addVertex(int** &adjMatrix, int &n, int u) {
    int** newAdjMatrix = new int*[n+1];
    for (int i = 0; i < n+1; i++) {
        newAdjMatrix[i] = new int[n+1];
        for (int j = 0; j < n+1; j++)
            newAdjMatrix[i][j] = 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            newAdjMatrix[i][j] = adjMatrix[i][j];
    adjMatrix = newAdjMatrix;
    n++;
}

// removeVertex
