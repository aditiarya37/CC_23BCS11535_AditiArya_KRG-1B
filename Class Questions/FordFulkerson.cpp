#include <bits/stdc++.h>
using namespace std;
#define V 6
bool dfs(int rGraph[V][V], int s, int t, bool visited[], int parent[]){
    visited[s] = true;
    if (s == t) return true;
    for (int v = 0; v < V; v++){
        if (!visited[v] && rGraph[s][v] > 0){
            parent[v] = s;
            if (dfs(rGraph, v, t, visited, parent)) return true;
        }
    }
    return false;
}
int fordFulkerson(int graph[V][V], int s, int t){
    int u, v;
    int rGraph[V][V];
    for (u = 0; u < V; u++){
        for (v = 0; v < V; v++){
            rGraph[u][v] = graph[u][v];
        }
    }
    int parent[V];
    int max_flow = 0;
    while (true){
        bool visited[V] = {false};
        if (!dfs(rGraph, s, t, visited, parent)) break;
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]){
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v = t; v != s; v = parent[v]){
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main(){
    int graph[V][V] = {
        {0,3,2,0},
        {0,0,5,2},
        {0,0,0,3},
        {0,0,0,0}
    };
    cout << "Maximum Flow = " << fordFulkerson(graph, 0, 3);
    return 0;
}