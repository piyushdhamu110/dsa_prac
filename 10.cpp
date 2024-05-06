// You have a business with several offices; you want to lease phone lines to connect them up
// with each other; and the phone company charges different amounts of money to connect
// different pairs of cities. You want a set of lines that connects all your offices with a minimum
// total cost. Solve the problem by suggesting appropriate data structures (Prim’s algorithm)

#include <bits/stdc++.h>
using namespace std;
#define V 5

int minKey(int key[], bool visited[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false && key[v] < min)
        {
            min = key[v], min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
    }
}

void primMST(int graph[V][V])
{

    int parent[V];
    int key[V];

    bool visited[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX, visited[i] = false;
    }

    key[0] = 0;

    // First node is always root of MST
    parent[0] = -1;

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {

        int u = minKey(key, visited);

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && visited[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

// Driver's code
int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    // Print the solution
    primMST(graph);

    return 0;
}