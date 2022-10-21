#include <iostream>
#include <list>
using namespace std;

// Graph class represents a undirected graph using adjacency list representation
class Graph {
    int V; // No. of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists
public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    bool canGo(int s, int d); 
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v's list.
}

bool Graph::canGo(int s, int d) {
    if (s == d)
      return true;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    while (!queue.empty()) {
        s = queue.front();
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (*i == d)
                return true;
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    return false;
}

int main() {
    int v = 21;
    Graph g(v);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 8);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 7);
    g.addEdge(8, 9);
    g.addEdge(8, 10);
    g.addEdge(10, 11);
    g.addEdge(10, 12);
    g.addEdge(10, 13);
    g.addEdge(13, 14);
    g.addEdge(13, 15);
    g.addEdge(15, 16);
    g.addEdge(15, 17);
    g.addEdge(17, 18);
    g.addEdge(17, 19);
    g.addEdge(17, 20);
    if (g.canGo(0, 20))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}