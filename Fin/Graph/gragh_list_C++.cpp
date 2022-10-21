#include <iostream>
#include <vector>
using namespace std;
// Function to create a graph with n vertices
vector<int>* createGraph(int n) {
    // Return array of n lists (vectors)
    return new vector<int>[n];
}
// Function to print the adjacency-list representation of graph
void printGraph(vector<int>* adjList, int V) {
    for (int v = 0; v < V; v++) {
        cout << "[" << v << "] head ";
        for (int i = 0; i < adjList[v].size(); i++) {
            cout << "-> " << adjList[v].at(i);
        }
        cout << endl;
    }
    cout << endl;
}
// Function to add edge into the graph
void addEdge(vector<int>* adjList, int u, int v) {
    adjList[u].push_back(v);
}
// Function to remove edge from the graph
void removeEdge(vector<int>* adjList, int u, int v) {
    for(int i=0; i<adjList[u].size(); i++) {
        if(adjList[u].at(i) == v) {
            adjList[u].erase(adjList[u].begin() + i);
            return;
        }
    }
}
// Function to add vertex from the graph
void addVertex(int &n, int u) {
    n = u+1;
}
// Function to remove vertex from the graph
void removeVertex(vector<int>* adjList, int &n, int u) {
    if (u < n-1)
        return;
    for (int v=0; v<n; v++)
        removeEdge(adjList, v, u);
    adjList[u].clear();
    n--;
}
// Function isAdjacent to check if two vertices are adjacent
bool isAdjacent(vector<int>* adjList, int u, int v) {
    for (int i=0; i<adjList[u].size(); i++)
        if (adjList[u].at(i) == v)
            return true;
    return false;
}
// Function inDegree to return the in-degree of a vertex
int inDegree(vector<int>* adjList, int n, int u) {
    int count = 0;
    for (int v=0; v<n; v++)
        for (int i=0; i<adjList[v].size(); i++)
            if (adjList[v].at(i) == u)
                count++;
    return count;
}
// Function outDegree to return the out-degree of a vertex
int outDegree(vector<int>* adjList, int u) {
    return adjList[u].size();
}
// Driver code
int main() {
    int n = 5;
    vector<int>* adjList = createGraph(n);
    //Vertex number should be 0 to n-1
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);
    printGraph(adjList, n);
    return 0;
}