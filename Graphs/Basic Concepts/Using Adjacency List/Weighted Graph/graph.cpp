#include<iostream>
#include<vector>
#include<list>
using namespace std;

// Graph class using adjacency list for weighted undirected graph
class Graph {
    int V; // Number of vertices
    list<pair<int, int>>* l; // Array of adjacency lists (vertex, weight)
public:

    // Constructor: initializes graph with V vertices
    Graph(int V) {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    // Adds an undirected edge with weight between u and v
    void addEdge(int u, int v, int wt) {
        l[u].push_back({ v, wt });
        l[v].push_back({ u, wt });
    }

    // Prints adjacency list of each vertex
    void print() {
        for (int u = 0; u < V; u++) {
            cout << u << " -> ";
            for (auto& v : l[u]) {
                cout << "(" << v.first << ", " << v.second << "), ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges (u, v, weight)
    graph.addEdge(0, 1, 5);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 2);

    // Print adjacency list
    graph.print();

    return 0;
}