#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> kahnTopologicalSort(int numCourses, vector<vector<int>> &prerequisites)
{
    // Step 1: Build graph
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);

    for (auto &edge : prerequisites)
    {
        int to = edge[0];
        int from = edge[1];
        graph[from].push_back(to);
        indegree[to]++;
    }

    // Step 2: Initialize queue with nodes having indegree 0
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Step 3: BFS Loop
    vector<int> topoOrder;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        for (int neighbor : graph[node])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    // Step 4: Check for cycles
    if (topoOrder.size() != numCourses)
    {
        // Cycle detected
        return {};
    }

    return topoOrder;
}

// Sample usage
int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}};

    vector<int> order = kahnTopologicalSort(numCourses, prerequisites);

    if (order.empty())
    {
        cout << "Cycle detected! No valid course order." << endl;
    }
    else
    {
        cout << "Valid Topological Order: ";
        for (int course : order)
        {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
