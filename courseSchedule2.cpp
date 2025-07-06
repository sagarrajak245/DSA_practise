

#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    unordered_map<int, vector<int>> buildgraph(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> graph;
        for (auto &it : prerequisites)
        {
            int a1 = it[0];
            int b1 = it[1];
            graph[b1].push_back(a1);
        }
        return graph;
    }

    // returns true if a cycle is found
    bool dfs(int node, vector<int> &visited, unordered_map<int, vector<int>> &gp, stack<int> &st)
    {
        visited[node] = 1; // visiting

        for (auto &neighbor : gp[node])
        {
            if (visited[neighbor] == 1)
            {
                return true; // cycle found
            }
            if (visited[neighbor] == 0)
            {
                if (dfs(neighbor, visited, gp, st))
                    return true;
            }
        }

        visited[node] = 2; // visited
        st.push(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        auto gp = buildgraph(numCourses, prerequisites);
        vector<int> visited(numCourses, 0);
        stack<int> st;

        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0)
            {
                if (dfs(i, visited, gp, st))
                {
                    return {}; // cycle detected, impossible to finish
                }
            }
        }

        vector<int> order;
        while (!st.empty())
        {
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }
};

int main()
{
    Solution sol;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}, {1, 3}};

    vector<int> order = sol.findOrder(numCourses, prerequisites);

    if (order.empty())
    {
        cout << "It's not possible to finish all courses." << endl;
    }
    else
    {
        cout << "Order of courses to finish: ";
        for (int course : order)
        {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
// This code implements a solution to the Course Schedule problem using DFS to detect cycles and find a