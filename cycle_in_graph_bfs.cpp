#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool bfs_cycle(int src, vector<int> &visited, vector<int> &parent, vector<vector<int>> &adj)
    {
        queue<pair<int, int>> q;
        q.push({src, -1});
        visited[src] = 1;

        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = 1;
                    parent[it] = node;
                    q.push({it, node});
                }
                else if (it != par)
                {
                    return true; // cycle detected
                }
            }
        }
        return false;
    }
};

int main()
{
    // Predefined number of nodes
    int n = 5;

    // Predefined adjacency list
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1};
    adj[3] = {4};
    adj[4] = {3};

    // Print the graph
    cout << "Graph adjacency list:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (auto v : adj[i])
            cout << v << " ";
        cout << endl;
    }

    // Cycle detection
    vector<int> visited(n, 0);
    vector<int> parent(n, -1);

    Solution obj;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (obj.bfs_cycle(i, visited, parent, adj))
            {
                cout << "Cycle detected in the graph." << endl;
                return 0;
            }
        }
    }

    cout << "No cycle detected in the graph." << endl;
    return 0;
}
