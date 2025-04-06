// Function to find sum of weights of edges of the Minimum Spanning Tree.
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    int sum = 0;
    vector<bool> visited(V, false);
    // can start from any random vertex. We'll start from 0.
    q.push({0, {0, -1}});
    while (!q.empty())
    {
        int node = q.top().second.first;
        int weight = q.top().first;
        q.pop();
        if (visited[node] == false)
        {
            visited[node] = true;
            sum += weight;
            for (auto &nums : adj[node])
            {
                q.push({nums[1], {nums[0], node}});
            }
        }
    }
    return sum;
}
