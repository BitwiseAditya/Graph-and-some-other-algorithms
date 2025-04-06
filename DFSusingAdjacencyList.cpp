#include <bits/stdc++.h>
using namespace std;
bool DepthFirstSearch(int n, int source, int destination, unordered_map<int, vector<int>> &adjList, vector<bool> &visitedArr)
{
    if (source == destination)
        return true;
    visitedArr[source] = true;

    for (auto nums : adjList[source])
    {
        if (!(visitedArr[nums]))
        {
            if (DepthFirstSearch(n, nums, destination, adjList, visitedArr))
            {
                return true;
            }
        }
    }

    return false;
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    unordered_map<int, vector<int>> adjList;
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<bool> visitedArr(n, false);
    return DepthFirstSearch(n, source, destination, adjList, visitedArr);
}

// Space Complexity - O(V+2E) + O(V) + O(V)
// Time Complexity - O(V+2E)
// 2E because the given graph is bi-directional. If it was uni-directional, instead of O(V + 2E), it would have been O(V+E) .
