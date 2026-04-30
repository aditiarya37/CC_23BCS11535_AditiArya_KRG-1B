#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int V, E;
    cin >> V >> E;
    vector<pair<int,int>> adj[V];
    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> vis(V,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    int sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int w = it.first;
        int node = it.second;
        if(vis[node]) continue;
        vis[node] = 1;
        sum += w;
        for(auto i: adj[node]){
            int adjNode = i.first;
            int weight = i.second;
            if(!vis[adjNode]) pq.push({weight,adjNode});
        }
    }
    cout << sum;
    return 0;
}