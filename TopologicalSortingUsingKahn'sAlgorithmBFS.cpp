// Topological Sorting using Kahn's Algorithm BFS:-
#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int V, vector<int> adj[])
{
    vector<int> inDegree(V, 0), topoOrder;
    queue<int> q;

    // Step 1: Calculate in-degree of all nodes
    for (int i = 0; i < V; i++)
        for (int v : adj[i])
            inDegree[v]++;

    // Step 2: Push nodes with in-degree 0 into queue
    for (int i = 0; i < V; i++)
        if (inDegree[i] == 0)
            q.push(i);

    // Step 3: Process queue
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        // Reduce in-degree of neighbors
        for (int v : adj[node])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }

    // If all nodes are processed, return the order; otherwise, return an empty list (cycle detected)
    return topoOrder.size() == V ? topoOrder : vector<int>();
}

int main()
{
    int V = 6;
    vector<int> adj[6] = {
        {2, 3}, // Node 0 → {2, 3}
        {3, 4}, // Node 1 → {3, 4}
        {},     // Node 2 → {}
        {5},    // Node 3 → {5}
        {5},    // Node 4 → {5}
        {}      // Node 5 → {}
    };

    vector<int> order = topologicalSort(V, adj);

    if (order.empty())
        cout << "Graph contains a cycle!\n";
    else
    {
        cout << "Topological Order: ";
        for (int node : order)
            cout << node << " ";
        cout << endl;
    }
}
