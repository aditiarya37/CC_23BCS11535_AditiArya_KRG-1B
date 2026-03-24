#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> solve(int n, vector<vector<int>> &prereq){
    vector<vector<int>> adj(n);
    vector<int> inDeg(n,0);
    for(auto p: prereq){
        int a = p[0];
        int b = p[1];
        adj[b].push_back(a);
        inDeg[a]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(inDeg[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i: adj[node]){
            inDeg[i]--;
            if(inDeg[i]==0) q.push(i);
        }
    }
    return ans;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> prereq(m,vector<int> (2));
    for(int i=0;i<m;i++){
        cin >> prereq[i][0] >> prereq[i][1];
    }
    vector<int> ans = solve(n, prereq);
    for(int i: ans){
        cout << i << " ";
    }
    return 0;
}