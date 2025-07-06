
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

    bool dfs(int node, vector<int> &visited, unordered_map<int, vector<int>> &gp)
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
                if (dfs(neighbor, visited, gp))
                    return true;
            }
        }

        visited[node] = 2; // visited
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        auto gp = buildgraph(numCourses, prerequisites);
        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0)
            {
                if (dfs(i, visited, gp))
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}, {1, 3}};

    Solution sol;
    if (sol.canFinish(numCourses, prerequisites))
    {
        cout << "All courses can be finished." << endl;
    }
    else
    {
        cout << "Cannot finish all courses due to a cycle." << endl;
    }

    return 0;
}
