#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

class graph
{
public:
    int V;
    vector<vector<pair<int, int>>> adjList;

    // Constructor
    graph(int V)
    {
        this->V = V;
        adjList.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int firstnode, int secondnode, int weight)
    {
        // Undirected graph
        adjList[firstnode].push_back(make_pair(secondnode, weight));
        adjList[secondnode].push_back(make_pair(firstnode, weight));
    }

    // Print the graph
    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Adjacency list of vertex " << i << ": ";
            for (auto it = adjList[i].begin(); it != adjList[i].end(); ++it)
                cout << "(" << it->first << "," << it->second << ") ";
            cout << endl;
        }
    }

    // Depth-first search traversal
    void dfs(int startnode)
    {
        vector<bool> visited(V, false);
        dfsUtil(startnode, visited);
    }

    // Utility function for DFS traversal
    void dfsUtil(int startnode, vector<bool> &visited)
    {
        visited[startnode] = true;
        cout << startnode << " ";

        for (auto &it : adjList[startnode])
        {
            int neighbor = it.first;
            if (!visited[neighbor])
            {
                dfsUtil(neighbor, visited);
            }
        }
    }

    // Function to find connected components using DFS
    void findConnectedComponents()
    {
        vector<bool> visited(V, false);

        cout << "Connected Components:\n";
        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
            {
                cout << "Component " << i << ": ";
                dfsUtil(i, visited);
                cout << endl;
            }
        }
    }
};

int main()
{
    // Create a graph with 5 vertices
    graph g(5);

    // Add edges with weights
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 6);
    g.addEdge(1, 3, 15);
    g.addEdge(1, 4, 8);
    g.addEdge(2, 3, 20);
    g.addEdge(3, 4, 9);

    // Print the graph
    g.printGraph();

    // Perform DFS traversal starting from vertex 0
    cout << "\nDFS traversal starting from vertex 0: ";
    g.dfs(0);
    cout << endl;

    // Find and print the connected components of the graph
    g.findConnectedComponents();

    return 0;
}
