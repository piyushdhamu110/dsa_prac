// Implement Dijkstra’s algorithm for shortest path between a given pair of vertices.
// Test your program for following example:

#include <iostream>
using namespace std;
#include <limits.h>

#define size 9

int minDistance(int distance[], bool visited[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < size; v++)
    {
        if (visited[v] == false && distance[v] <= min)
        {
            min = distance[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int distance[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < size; i++)
        cout << i << " \t\t\t\t" << distance[i] << endl;
}

void dijkstra(int graph[size][size], int startingIndex)
{
    int distance[size];

    bool visited[size];

    for (int i = 0; i < size; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[startingIndex] = 0;

    for (int count = 0; count < size - 1; count++)
    {

        int u = minDistance(distance, visited);

        visited[u] = true;

        for (int v = 0; v < size; v++)
        {
            if (!visited[v] && graph[u][v] != 0 && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }
    printSolution(distance);
}

int main()
{
    int graph[size][size] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                             {4, 0, 8, 0, 0, 0, 0, 11, 0},
                             {0, 8, 0, 7, 0, 4, 0, 0, 2},
                             {0, 0, 7, 0, 9, 14, 0, 0, 0},
                             {0, 0, 0, 9, 0, 10, 0, 0, 0},
                             {0, 0, 4, 14, 10, 0, 2, 0, 0},
                             {0, 0, 0, 0, 0, 2, 0, 1, 6},
                             {8, 11, 0, 0, 0, 0, 1, 0, 7},
                             {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}
