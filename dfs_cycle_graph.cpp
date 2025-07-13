#include <iostream>
#include <vector>
using namespace std;

// DFS cycle detection in undirected graph
bool dfs_cycle(int node, vector<int> &visited, int parent, vector<vector<int>> &adj)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            if (dfs_cycle(it, visited, node, adj))
                return true;
        }
        else if (it != parent)
        {
            return true; // cycle detected
        }
    }
    return false;
}

bool hasCycle(int n, vector<vector<int>> &adj)
{
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs_cycle(i, visited, -1, adj))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n = 5; // nodes 0..4

    // manually define adjacency list
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1};
    adj[3] = {4};
    adj[4] = {3};

    // Print graph
    cout << "Graph adjacency list:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (auto v : adj[i])
            cout << v << " ";
        cout << endl;
    }

    // Check for cycle
    if (hasCycle(n, adj))
    {
        cout << "Graph has a cycle." << endl;
    }
    else
    {
        cout << "Graph has no cycle." << endl;
    }

    return 0;
}
