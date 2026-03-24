#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st){
    vis[node] = true;
    for(int i: adj[node]){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }
    st.push(node);
}
int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for(int i=0;i<E;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<bool> vis(V, false);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}