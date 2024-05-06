// Write a program to represent input graph using adjacency matrix.Implement Depth First and Breadth first traversal algorithms.Check if graph is connected, if not find how many connected components it has.

#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 100;
int graph[MAX_NODES][MAX_NODES] = {0};

void addEdge(int x, int y)
{
    graph[x][y] = 1;
    graph[y][x] = 1;
}

// Depth First Search function
void DFS(int nodes, int start, bool visited[])
{
    stack<int> st;
    st.push(start);
    visited[start] = true;

    while (!st.empty())
    {
        int current = st.top();
        st.pop();
        cout << current << " ";

        for (int i = 0; i < nodes; ++i)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                st.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int nodes, int start, bool visited[])
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 0; i < nodes; ++i)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS_Util(int nodes, int current, bool visited[])
{
    visited[current] = true;
    for (int i = 0; i < nodes; ++i)
    {
        if (graph[current][i] && !visited[i])
        {
            DFS_Util(nodes, i, visited);
        }
    }
}

bool isConnected(int nodes)
{
    bool visited[MAX_NODES] = {false};
    int startNode = 0;
    DFS_Util(nodes, startNode, visited);

    for (int i = 0; i < nodes; ++i)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges: ";
    cin >> edges;

    bool visited[MAX_NODES] = {false};

    // for (int i = 0; i < edges; ++i)
    // {
    //     int node1, node2;
    //     cout << "Node1: ";
    //     cin >> node1;
    //     cout << "Node2: ";
    //     cin >> node2;
    //     addEdge(node1, node2);
    // }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 5);
    addEdge(2, 5);

    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    cout << "Depth First Traversal starting from node " << startNode << ": ";
    DFS(nodes, startNode, visited);
    cout << endl;

    // Reset visited array for BFS
    memset(visited, false, sizeof(visited));

    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    cout << "Breadth First Traversal starting from node " << startNode << ": ";
    BFS(nodes, startNode, visited);
    cout << endl;

    // Reset visited array for BFS
    memset(visited, false, sizeof(visited));

    cout << "Checking whether graph is connected or not:  ";

    if (isConnected(nodes))
    {
        cout << "Graph is connected.\n";
    }
    else
    {
        cout << "Graph is not connected.\n";
    }

    return 0;
}
