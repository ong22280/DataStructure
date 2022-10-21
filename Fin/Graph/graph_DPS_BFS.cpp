#include <iostream>
#include <list>
using namespace std;

// Graph class represents a undirected graph using adjacency list representation
class Graph {
    int V; // No. of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists
    void DFSVisit(int s, bool visited[]); // A function used by DFS
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void DFSInit(int s); // DFS traversal of the vertices reachable from s
    void BFSVisit(int s); // BFS traversal of the vertices reachable from s
    void printGraph(); // prints adjacency list representation of graph
    bool isCyclic();    // returns true if there is a cycle in this graph
    bool isReachable(int s, int d); 
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v's list.
    adj[w].push_back(v); // Add v to w's list.
}

void Graph::DFSVisit(int s, bool visited[]) {
    // Mark the current node as visited and print it
    visited[s] = true;
    cout << s << " ";
    // Recurse for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!visited[*i])
            DFSVisit(*i, visited);
}

// DFS traversal of the vertices reachable from v
void Graph::DFSInit(int s) {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    // Call the recursive helper function to print DFS traversal
    DFSVisit(s, visited);
}

// BFS traversal of the vertices reachable from s
void Graph::BFSVisit(int s) {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    // Create a queue for BFS
    list<int> queue;
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
    // 'i' will be used to get all adjacent vertices of a vertex u
    list<int>::iterator i;
    int u;

    while(!queue.empty()) {
        // Dequeue a vertex from queue and print it
        u = queue.front();
        cout << u << endl;
        queue.pop_front();
        // Get all adjacent vertices of the dequeued vertex u
        // If a adjacent has not been visited, then mark it visited and enqueue it
        for(i = adj[u].begin(); i != adj[u].end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

// This function is a variation of DFSUtil() in 
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) {
    if(visited[v] == false) {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i) {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS()
bool Graph::isCyclic() {
    // Mark all the vertices as not visited and not part of recursion stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }
    // Call the recursive helper function to detect cycle in different DFS trees
    // DFS trees
    for(int i = 0; i < V; i++)
        if ( !visited[i] && isCyclicUtil(i, visited, recStack) )
            return true;
    return false;
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
    cin >> v >> e;
    Graph g(v);
    while(e--) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << endl;
    g.DFSInit(0);
    cout << endl;
    g.BFSVisit(0);
    cout << endl;
    
    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    
    int s, t;
    cin >> s >> t;
    if (g.isReachable(s, t))
        cout << "True";
    else
        cout << "False";

    return 0;

}