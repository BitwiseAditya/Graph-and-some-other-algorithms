/* Given an undirected graph with v vertices(numbered from 1 to v) and e edges. Find the number of good components in the graph.
A component of the graph is good if and only if the component is fully connected.
Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of vertices in the component,
 the given graph can be a disconnected graph.
Example 1 :-
e=3
v=3
edges={{1, 2},{1, 3},{3, 2}}
Output:
1
Explanation:
We can see that there is only one component in the graph and in this component there is a edge between any two vertces.
Example 2 :-
e=5
v=7
edges={{1, 2},{7, 2},{3, 5},{3, 4},{4, 5}}
Output:
2
Explanation:
We can see that there are 3 components in the graph. For 1-2-7 there is no edge between 1 to 7, so it is not a fully connected component. Rest 2 are individually fully connected component.
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isitGood(int i, unordered_map<int, vector<int>> &graph, vector<bool> &visited, int v)
    {
        if (graph.find(i) == graph.end())
        {
            visited[i] = true;
            return true;
        }
        vector<int> part;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int a = q.front();
            q.pop();
            visited[a] = true;
            part.push_back(a);
            for (int i = 0; i < graph[a].size(); i++)
            {
                if (!visited[graph[a][i]])
                {
                    q.push(graph[a][i]);
                    visited[graph[a][i]] = true;
                }
            }
        }
        for (int i = 0; i < part.size(); i++)
        {
            for (int j = 0; j < part.size(); j++)
            {
                if (i != j)
                {
                    if (find(graph[part[i]].begin(), graph[part[i]].end(), part[j]) == graph[part[i]].end())
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges)
    {
        // code here
        int count = 0;
        unordered_map<int, vector<int>> graph;
        for (auto &it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<bool> visited(v + 1, false);
        for (int i = 1; i <= v; i++)
        {
            if (!visited[i])
            {
                if (isitGood(i, graph, visited, v))
                {
                    count += 1;
                }
            }
        }
        return count;
    }
};
