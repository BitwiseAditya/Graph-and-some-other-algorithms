#include <bits/stdc++.h>
using namespace std;

void BellmanFord(int graph[][3], int V, int E, int src)
{
    int dis[V];
    for (int i = 0; i < V; i++)
        dis[i] = INT_MAX;
    dis[src] = 0;

    // Relax edges |V| - 1 times
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            if (dis[graph[j][0]] != INT_MAX && dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < E; i++)
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x] != INT_MAX && dis[x] + weight < dis[y])
        {
            cout << "Graph contains a negative weight cycle\n";
            return;
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dis[i] << "\n";
}

int main()
{
    int V = 5; // Number of vertices
    int E = 8; // Number of edges
    int graph[][3] = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    int source = 0; // Source vertex
    BellmanFord(graph, V, E, source);

    return 0;
}

// This algo cannot be applied to undirected graphs, because directed mein convert karne pe negative weight cycle will be formed.
