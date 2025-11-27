#include <iostream> // cout, endl
#include <list>     // adjacency lists
#include <vector>   // (kept for consistency / future use)
using namespace std;

// Simple undirected graph using adjacency lists
class Graph {
    int V;             // number of vertices
    list<int>* l;      // array of adjacency lists
public:

    // construct graph with V vertices
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    // add an undirected edge between u and v
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // print adjacency list of each vertex
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
};

int main() {
    // demo: small graph with 5 vertices
    Graph graph(5);

    // add undirected edges
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);

    // display adjacency lists
    graph.print();
    return 0;
}