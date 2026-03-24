#include <bits/stdc++.h>
using namespace std;

#define V 4

bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V] = {false};
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

int edmondKarp(int graph[V][V], int s, int t)
{
    int rGraph[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            rGraph[i][j] = graph[i][j];

    int parent[V];
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;

        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    int graph[V][V] = {
        {0, 3, 2, 0},
        {0, 0, 5, 2},
        {0, 0, 0, 3},
        {0, 0, 0, 0}
    };

    int source = 0;
    int sink = 3;

    cout << "Maximum Flow = "
         << edmondKarp(graph, source, sink);

    return 0;
}