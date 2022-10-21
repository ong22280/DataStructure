#include<stdio.h>

// Implementation of singly linked list
struct Node {
    int adj_vertex;
    struct Node* next;
};

// Create the graph using adjacency-list representation
struct Node** createGraph(int n) {
    // Return array of size n lists (vectors)
    struct Node** adjList = (struct Node*)malloc(n*sizeof(struct Node));
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }
    return adjList;
}

// Add the edge to the graph using adjacency-list representation
void addEdge(struct Node** adjList, int u, int v) {
    struct Node* node = adjList[u];
    if (node == NULL) {
        node = malloc(sizeof(struct Node));
        node->adj_vertex = v;
        node->next = NULL;
        adjList[u] = node;
    } else {
        while (node->next != NULL) {
            node = node->next;
        }
        struct Node* new_node = malloc(sizeof(struct Node));
        new_node->adj_vertex = v;
        new_node->next = NULL;
        node->next = new_node;
    }
}

// Print the graph using adjacency-list representation
void printGraph(struct Node** adjList, int n) {
    for (int u = 0; u < n; u++) {
        printf("[%d] head: ", u);
        struct Node* node = adjList[u];
        while (node != NULL) {
            printf("-> %d\n", node->adj_vertex);
            node = node->next;
        }
        printf("-> NULL \n");
    }
}

// Delete the adjacency-list representation of the graph
void deleteGraph(struct Node** adjList, int n) {
    for (int u = 0; u < n; u++) {
        struct Node* node = adjList[u];
        while (node != NULL) {
            struct Node* next_node = node->next;
            free(node);
            node = next_node;
        }
    }
    free(adjList);
}

// Remove the existing edge from the graph using adjacency-list representation
void removeEdge(struct Node** adjList, int u, int v) {
    struct Node* node = adjList[u];
    if (node->adj_vertex == v) {
        adjList[u] = node->next;
        free(node);
        return;
    } else {
        while (node->next != NULL) {
            struct Node* prev_node;
            node = node->next;
            if (node->adj_vertex != v) {
                prev_node = node;
                node = node->next;
            }
            prev_node->next = node->next;
            free(node);
        }
    }
}

// Add the new vertex to the graph using adjacency-list representation
struct Node** addVertex(struct Node** adjList, int *n, int u) {
    struct Node** adjList_new = createGraph(u+1);
    for (int i = 0; i < *n; i++) {
        adjList_new[i] = adjList[i];
        adjList[i] = NULL;
    }
    deleteGraph(adjList, *n);
    *n = u+1;
    return adjList_new;
}

// Remove the vertex from the graph using adjacency-list representation
void removeVertex(struct Node** adjList, int *n, int u) {
    for (int  v=0; v < *n; v++) {
        if (isAdjacent(adjList, v, u) == 1) {
            removeEdge(adjList, v, u);
        }
    }
    struct Node* node = adjList[u];
    while (node != NULL) {
        struct Node* next_node = node->next;
        free(node);
        node = next_node;
    }
    adjList[u] = NULL;
    if (u < *n-1) {
        return;
    }
    (*n)--;
}

// Check whether the two vertices are adjacent using adjacency-list representation
int isAdjacent(struct Node** adjList, int u, int v) {
    struct Node* node = adjList[u];
    int ret = 0;
    while (node != NULL) {
        if (node->adj_vertex == v) {
            ret = 1;
            return ret;
        }
        node = node->next;
    }
    return ret;
}

// Report the in-degree of the vertex using adjacency-list representation
int inDegree(struct Node** adjList, int n, int u) {
    int in_degree = 0;
    for (int i = 0; i < n; i++) {
        struct Node* node = adjList[i];
        while (node != NULL) {
            if (node->adj_vertex == u) {
                in_degree++;
            }
            node = node->next;
        }
    }
    return in_degree;
}

// Report the out-degree of the vertex using adjacency-list representation
int outDegree(struct Node** adjList, int n, int u) {
    struct Node* node = adjList[u];
    int out_degree = 0;
    while (node != NULL) {
        out_degree++;
        node = node->next;
    }
    return out_degree;
}