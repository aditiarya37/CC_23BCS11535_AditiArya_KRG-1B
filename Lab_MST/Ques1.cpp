#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
static bool cmp(vector<int> &a, vector<int> &b){
    return (b[1] - b[0]) < (a[1] - a[0]);
}
int main(){
    vector<vector<int>> energy;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        energy.push_back({a,b});
    }
    sort(energy.begin(), energy.end(), cmp);
    int curr = 0;
    int ans = 0;
    for (int i=0;i<energy.size();i++){
        int mini = energy[i][1];
        int act = energy[i][0];
        if (curr<mini){
            ans += mini-curr;
            curr = mini;
        }
        curr -= act;
    }
    cout << ans;
    return 0;
}