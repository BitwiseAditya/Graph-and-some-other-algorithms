#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class Graph {
private:
    int numVertices;
    list<int>* adjacencyList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList = new list<int>[vertices];
    }

    void addEdge(int from, int to) {
        // Since it's an undirected graph, we add both entries
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from);
    }

    void display() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            cout << "Vertex " << i << " :";
            for (const auto& neighbor : adjacencyList[i]) {
                cout << " -> " << neighbor;
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Display the adjacency list
    graph.display();

    return 0;
}
