//Representing an Undirected Graph using an Adjacency Matrix.


#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int from, int to) {
        // Since it's an undirected graph, we update both entries
        adjacencyMatrix[from][to] = 1;
        adjacencyMatrix[to][from] = 1;
    }

    void display() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
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

    // Display the adjacency matrix
    graph.display();

    return 0;
}
