#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
    int V;                   // No. of vertices
    vector<vector<int>> adj; // Adjacency list

    // DFS traversal used by topologicalSort
    void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack)
    {
        // Mark the current node as visited
        visited[v] = true;

        // Recur for all the vertices adjacent to this vertex
        for (int i : adj[v])
        {
            if (!visited[i])
                topologicalSortUtil(i, visited, Stack);
        }

        // Push current vertex to stack which stores result
        Stack.push(v);
    }

public:
    Graph(int V) : V(V)
    {
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    // Function to perform Topological Sort
    void topologicalSort()
    {
        stack<int> Stack;
        vector<bool> visited(V, false);

        // Call the recursive helper function to store Topological Sort
        // starting from all vertices one by one
        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
                topologicalSortUtil(i, visited, Stack);
        }

        // Print contents of stack
        while (!Stack.empty())
        {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }
};

int main()
{
    // Create a graph given in the example
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Topological Sort of the given graph is \n";
    g.topologicalSort();

    return 0;
}
// Note : Topo Sort is valid only for DAG (Directed Acyclic Graph).
/* Note : If a topo sort of a graph has less no. of vertices relative to total number of vertices in graph, that implies
   that the directed graph has a cycle.This is a way to detect cycle in a directed graph. */
