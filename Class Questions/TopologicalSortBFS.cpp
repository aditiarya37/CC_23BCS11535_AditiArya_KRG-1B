#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    vector<int> inDeg(V,0);
    for(int i=0;i<E;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDeg[v]++;
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(inDeg[i]==0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(int i: adj[node]){
            inDeg[i]--;
            if(inDeg[i]==0){
                q.push(i);
            }
        }
    }
    for(int i=0;i<topo.size();i++){
        cout << topo[i] << " ";
    }
    return 0;
}