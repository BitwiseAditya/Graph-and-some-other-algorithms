/*
Given a tree with n nodes where n is even. The tree is numbered from 1 to n,
has n - 1 edges and is rooted at node 1. Your task is to eliminate the maximum
number of edges resulting in a set of disjoint trees where the number of nodes
in each tree is divisible by 2.

Example 1:

Input:
n = 10
edges = {{2,1},{3,1},{4,3},{5,2},{6,1},{7,2},{8,6},{9,8},{10,8}}
Output:
2
Explanation:
After removing edge 1-3 and 1-6, each remaining component consists of even number of nodes.

Example 2 :

Input:
n = 4
edges = {{2,1},{4,2},{1,3}}
Output:
1
Explanation:
After removing 2-1, each remaining component consists of even number of nodes.

Your Task:
You don't need to read or print anyhting. Your task is to complete
the function minimumEdgeRemove() which takes n and edges as input
parameters and returns the maximum number of edges that need to be
removed from the given tree.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
int dfs(unordered_map<int, vector<int>> &graph, vector<bool> &visited, int node, int &ans)
{
    visited[node] = true;
    int count = 0;
    for (auto &it : graph[node])
    {
        if (visited[it] == false)
        {
            int res = dfs(graph, visited, it, ans);
            if (res % 2 == 0)
            {
                ans += 1;
            }
            else
            {
                count += res;
            }
        }
    }
    return count + 1;
}
int minimumEdgeRemove(int n, vector<vector<int>> edges)
{
    // Code here
    unordered_map<int, vector<int>> graph;
    for (auto &edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(n + 1, false);
    int ans = 0;
    dfs(graph, visited, 1, ans);
    return ans;
}
