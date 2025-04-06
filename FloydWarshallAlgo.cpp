#include <iostream>
#include <vector>

using namespace std;

#define INF 99999

// Function to implement Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(graph);

    // Updating distance matrix with shortest paths
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Printing the shortest distances
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    // Number of vertices in the graph
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Creating adjacency matrix representation of the graph
    vector<vector<int>> graph(V, vector<int>(V, INF));
    cout << "Enter the adjacency matrix (INF for infinity):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    // Applying Floyd-Warshall algorithm
    floydWarshall(graph, V);

    return 0;
}

