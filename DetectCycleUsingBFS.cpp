// program to detect cycles in an undirected graph
// using BFS
// Given Adjacency List adj.
#include <bits/stdc++.h>
using namespace std;
bool isCycle(int v, vector<int> adj[])
{
    vector<int> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (detectCycle(i, adj, visited))
            {
                return true;
            }
        }
    }
    return false;
}

bool detectCycle(int src, vector<int> adj[], vector<int> visited)
{
    visited[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjNode : adj[node])
        {
            if (!visited[adjNode])
            {
                visited[adjNode] = 1;
                q.push({adjNode, node});
            }
            else if (parent != adjNode)
            {
                return true;
            }
        }
    }
    return false;
}
