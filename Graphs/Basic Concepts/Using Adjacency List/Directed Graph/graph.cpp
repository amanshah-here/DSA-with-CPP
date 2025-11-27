#include<iostream>
#include<vector>
#include<list>
using namespace std;

// Graph class using adjacency list representation
class Graph {
    int V;           // Number of vertices
    list<int>* l;    // Adjacency list array
public:

    // Constructor: Initialize graph with V vertices
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    // Add directed edge from u to v
    void addEdge(int u, int v) {
        l[u].push_back(v);
    }

    // Print the adjacency list representation
    void print() {
        for (int u = 0; u < V; u++) {
            cout << u << " -> ";
            for (int v : l[u]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add directed edges
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(3, 1);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(4, 2);

    // Display the graph
    graph.print();

    return 0;
}