#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

// Graph class using adjacency list
class Graph {
    int V;                // Number of vertices
    list<int>* l;         // Array of adjacency lists
public:

    // Constructor: initializes graph with V vertices
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    // Adds an undirected edge between u and v
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // Prints adjacency list of each vertex
    void print() {
        for (int u = 0; u < V; u++) {
            list<int> neighbours = l[u];
            cout << u << " -> ";
            for (int v : neighbours) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    // Breadth-First Search traversal starting from vertex 0
    void BFS() {    // O(V + E)
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(0);      // Start BFS from vertex 0
        vis[0] = true;  // Mark vertex 0 as visited

        while (!q.empty()) {
            int u = q.front(); // Get next vertex from queue
            q.pop();

            cout << u << " "; // Print the vertex

            // Visit all unvisited neighbours
            for (int v : l[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph graph(7); // Create a graph with 7 vertices

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    graph.BFS(); // Perform BFS traversal
    return 0;
}