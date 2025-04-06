// program to detect cycles in an undirected graph
// using DFS
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
            if (detectCycleDFS(i, -1, adj, visited))
            {
                return true;
            }
        }
    }
    return false;
}

bool detectCycleDFS(int src, int parent, vector<int> &adj[], vector<int> &visited)
{
    visited[src] = 1;
    for (auto adjNode : adj[src])
    {
        if (!visited[adjNode])
        {
            if (detectCycleDFS(adjNode, src, adj, visited))
                return true;
        }
        else if (adjNode != parent)
            return true;
    }
    return false;
}