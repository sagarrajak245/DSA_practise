#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    unordered_map<string, vector<pair<string, double>>> buildGraph(
        vector<vector<string>> &equations,
        vector<double> &values)
    {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            graph[u].push_back({v, val});
            graph[v].push_back({u, 1.0 / val});
        }
        return graph;
    }

    vector<double> bfs(
        unordered_map<string, vector<pair<string, double>>> &gp,
        vector<vector<string>> &queries,
        vector<double> &result)
    {
        for (auto &query : queries)
        {
            string u = query[0];
            string v = query[1];

            if (gp.find(u) == gp.end() || gp.find(v) == gp.end())
            {
                result.push_back(-1.0);
            }
            else if (u == v)
            {
                result.push_back(1.0);
            }
            else
            {
                unordered_set<string> visited;
                queue<pair<string, double>> q;
                q.push(make_pair(u, 1.0));
                visited.insert(u);
                bool found = false;

                while (!q.empty())
                {
                    pair<string, double> current = q.front();
                    string node = current.first;
                    double value = current.second;
                    q.pop();

                    if (node == v)
                    {
                        result.push_back(value);
                        found = true;
                        break;
                    }

                    for (auto &neighbour : gp[node])
                    {
                        string next_node = neighbour.first;
                        double weight = neighbour.second;
                        if (visited.find(next_node) == visited.end())
                        {
                            visited.insert(next_node);
                            q.push(make_pair(next_node, value * weight));
                        }
                    }
                }
                if (!found)
                {
                    result.push_back(-1.0);
                }
            }
        }
        return result;
    }

    vector<double> calcEquation(
        vector<vector<string>> &equations,
        vector<double> &values,
        vector<vector<string>> &queries)
    {
        vector<double> result;
        auto gp = buildGraph(equations, values);
        return bfs(gp, queries, result);
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    vector<double> result = sol.calcEquation(equations, values, queries);

    for (double res : result)
    {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
