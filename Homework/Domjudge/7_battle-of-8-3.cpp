#include <iostream>
#include <list>
#include <vector>
using namespace std;

// Graph class represents a undirected graph using adjacency list representation
class Graph {
    int V; // No. of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists
public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void printShortestDistance(int s, int dest);
    bool isReachable(int s, int d);
    // sort graph ascending order by number
    void sortGraph();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v's list.
    adj[w].push_back(v); // Add v to w's list.
}

// sort graph ascending order by number
void Graph::sortGraph() {
    for (int i = 0; i < V; i++) {
        adj[i].sort();
    }
}

// printShortestDistance
// Shortest path length is :
// Path is :
void Graph::printShortestDistance(int s, int dest) {
    // Base case
    if (s == d)
      return;
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    // Create a queue for BFS
    list<int> queue;
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
    // it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            // If this adjacent node is the destination node, then
            // return true
            if (*i == d)
                return;
            // Else, continue to do BFS
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    // If BFS is complete without visiting d
    return;

}

bool Graph::isReachable(int s, int d) {
    // Base case
    if (s == d)
      return true;
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    // Create a queue for BFS
    list<int> queue;
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
    // it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            // If this adjacent node is the destination node, then
            // return true
            if (*i == d)
                return true;
            // Else, continue to do BFS
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    // If BFS is complete without visiting d
    return false;
}

int main() {
    int v, e;
    int distance = 0;
    int path[MAX_PATH];
    cin >> v >> e;
    Graph g(v);
    while (e--) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    // sort graph by ascending order number
    // g.sortGraph();
    int s, d;
    cin >> s >> d;
    if (g.isReachable(s, d)) {
        g.printShortestDistance(s, d);
        cout << "Yes" << endl;
    }
    else
        cout << "404: Path not found :(" << endl;
    return 0;

}