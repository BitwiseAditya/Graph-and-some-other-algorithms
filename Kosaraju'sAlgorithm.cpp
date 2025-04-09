/* Strongly Connected

Given an adjacency list, adj of Directed Graph, Find the number of strongly connected components in the graph.


Examples :

Input: adj[][] = [[2, 3], [0], [1], [4], []]

Output: 3
Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.

Input: adj[][] = [[1], [2], [0]]

Output: 1
Explanation: All of the nodes are connected to each other. So, there's only one SCC.
Input: adj[][] = [[1], []]
Output: 2
Constraints:
2<=adj.size()<=106
0<=edges<=adj.size()-1 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Position this line where user code will be pasted.
class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st, int index)
    {
        visited[index] = true;
        int n = adj[index].size();
        for (int i = 0; i < n; i++)
        {
            if (visited[adj[index][i]] == false)
            {
                dfs(adj, visited, st, adj[index][i]);
            }
        }
        st.push(index);
    }
    void dfs1(unordered_map<int, vector<int>> &graph, vector<bool> &visited, int index)
    {
        visited[index] = true;
        int n = graph[index].size();
        for (int i = 0; i < n; i++)
        {
            if (visited[graph[index][i]] == false)
            {
                dfs1(graph, visited, graph[index][i]);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj)
    {
        // code here
        stack<int> st;
        int n = adj.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                dfs(adj, visited, st, i);
            }
        }
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++)
        {
            int m = adj[i].size();
            for (int j = 0; j < m; j++)
            {
                graph[adj[i][j]].push_back(i);
            }
        }
        int count = 0;
        vector<bool> visited1(n, false);
        while (!st.empty())
        {
            int ind = st.top();
            st.pop();
            if (visited1[ind] == false)
            {
                visited1[ind] = true;
                dfs1(graph, visited1, ind);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends