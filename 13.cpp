// Given a directed acyclic graph, a. write a program for topological ordering of vertices b. DFS traversal

#include <bits/stdc++.h>
using namespace std;

void topologicalSortUtil(int v, vector<vector<int>> &adj, bool visited[], stack<int> &Stack)
{
    visited[v] = true;

    for (int i = 0; i < adj[v].size(); i++)
    {
        int current = adj[v][i];
        if (!visited[current])
        {
            topologicalSortUtil(current, adj, visited, Stack);
        }
    }

    Stack.push(v);
}

void topologicalSort(vector<vector<int>> &adj, int V)
{
    stack<int> Stack;
    bool visited[V] = {false};

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, adj, visited, Stack);
        }
    }

    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}

// void dfs(int v, bool visited[], vector<vector<int>> &adj)
// {
//     visited[v] = true;
//     cout << v << " ";
//     for (int i = 0; i < adj[v].size(); i++)
//     {
//         int current = adj[v][i];
//         if (!visited[current])
//         {
//             dfs(current, visited, adj);
//         }
//     }
// }

// void depthFirstSearch(vector<vector<int>> &adj, int V)
// {
//     bool visited[V] = {false};
//     cout << "DFS traversal: ";
//     for (int i = 0; i < V; i++)
//     {
//         if (!visited[i])
//         {
//             dfs(i, visited, adj);
//         }
//     }
//     cout << endl;
// }

// void dfs(vector<vector<int>> adj, int n)
// {
//     bool visited[n] = {false};
//     stack<int> s;
//     s.push(0);

//     while (!s.empty())
//     {
//         int top = s.top();
//         s.pop();

//         cout << top << " ";

//         for (int i = 0; i < adj[top].size(); i++)
//         {
//             int current = adj[top][i];
//             if(!visited[current])
//             {
//                 s.push(current);
//                 visited[current] = true;
//             }
//         }
        
//     }
// }

void DFSUtil(int v, vector<bool> &visited, vector<vector<int>> &adj)
{
    visited[v] = true;
    cout << v << " ";

    for (int i : adj[v])
    {
        if (!visited[i])
            DFSUtil(i, visited,adj);
    }
}

void DFS(int start, int V, vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);
    cout << "DFS traversal starting from vertex " << start << ": ";
    DFSUtil(start, visited,adj);
}

void breadthFirstSearch(vector<vector<int>> &adj, int V)
{
    bool visited[V] = {false};
    cout << "BFS traversal: ";
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                cout << v << " ";
                for (int j = 0; j < adj[v].size(); j++)
                {
                    int current = adj[v][j];
                    if (!visited[current])
                    {
                        q.push(current);
                        visited[current] = true;
                    }
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    int V = 4;
    bool visited[4] = {false};
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}, {3, 3}};

    vector<vector<int>> adj(V);

    for (int i = 0; i < V; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    cout << "Topological sorting of the graph: ";
    topologicalSort(adj, V);

    DFS(0,adj.size(),adj);

    breadthFirstSearch(adj, V);

    return 0;
}
