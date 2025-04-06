/* There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise. */

#include <bits/stdc++.h>
using namespace std;
bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<bool>> adjMatrix(n, vector<bool>(n, false));
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adjMatrix[u][v] = true;
        adjMatrix[v][u] = true;
    }

    vector<bool> visitedArr(n, false);
    queue<int> que;

    que.push(source);
    visitedArr[source] = true;

    while (!(que.empty()))
    {
        int curr = que.front();
        que.pop();
        if (curr == destination)
            return true;
        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[curr][i] && !(visitedArr[i]))
            {
                que.push(i);
                visitedArr[i] = true;
            }
        }
    }
    return false;
}
