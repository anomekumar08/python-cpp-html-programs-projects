BFS and DFS traversal of a graph using adjacency list

// BFS Traversal using adjacency list
// Code

// optimised code 

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V; 
    vector<vector<int>> adj; // Using vector of vectors instead of list
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    vector<bool> visited(V, false);
    queue<int> q; // Using queue instead of list

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        cout << v << " ";
        q.pop();

        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal (starting from vertex 2):\n";
    g.BFS(2);
    return 0;
}


// DFS Traversal using adjacency list.
// code

// optmised code

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj; // Using vector of vectors instead of list
    vector<bool> visited; // Moved visited to be a member variable
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
private:
    void DFSUtil(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
    visited.resize(V, false); // Initialize visited vector in constructor
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFS(int v) {
    fill(visited.begin(), visited.end(), false); // Ensure visited is reset before every DFS
    DFSUtil(v);
}

void Graph::DFSUtil(int v) {
    visited[v] = true;
    cout << v << " ";

    for (int u : adj[v]) {
        if (!visited[u]) {
            DFSUtil(u);
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal (starting from vertex 2):\n";
    g.DFS(2);
    return 0;
}
