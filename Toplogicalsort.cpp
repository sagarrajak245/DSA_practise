#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// toplogical sort using dfs
class Solution
{
public:
    void dfs(int node, vector<int> &visited, stack<int> &st, vector<vector<int>> &adj)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, visited, st, adj);
            }
        }
        st.push(node);
    }
    vector<int> topologicalSort(int n, vector<vector<int>> &adj)
    {
        vector<int> visited(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, st, adj);
            }
        }
        vector<int> topoOrder;
        while (!st.empty())
        {
            topoOrder.push_back(st.top());
            st.pop();
        }
        return topoOrder;
    }

    // bool return if toplogical possible or not

    bool dfsDetectCycle(int node, vector<int> &visited, vector<vector<int>> &adj)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (visited[it] == 1)
                return true;
            if (visited[it] == 0)
            {
                if (dfsDetectCycle(it, visited, adj))
                    return true;
            }
        }
        visited[node] = 2;
        return false;
    }

    bool isTopologicalSortPossible(int n, vector<vector<int>> &adj)
    {
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                if (dfsDetectCycle(i, visited, adj))
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<int>> adj = {
        {1, 2},
        {3},
        {3},
        {}};
    int n = adj.size();
    Solution sol;
    vector<int> topoOrder = sol.topologicalSort(n, adj);
    cout << "Topological Sort Order: ";
    for (int node : topoOrder)
    {
        cout << node << " ";
    }
    cout << endl;
    // Output: Topological Sort Order: 0 1 2 3
    // Explanation: The topological sort order of the given directed acyclic graph is 0 1 2 3.
    // Node 0 comes before nodes 1 and 2, and nodes 1 and 2 come before node 3.
    // This order respects the directed edges in the graph.
    // Note: The order may vary as long as it respects the dependencies.
    // The output may vary based on the implementation of the DFS and stack.
    // The topological sort is not unique; there can be multiple valid orders.
    bool isPossible = sol.isTopologicalSortPossible(n, adj);
    if (isPossible)
    {
        cout << "Topological sort is possible." << endl;
    }
    else
    {
        cout << "Topological sort is not possible." << endl;
    }

    return 0;
}