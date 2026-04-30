#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int n;
int cost[20][20];
int dp[1<<15][15];

int solve(int mask, int pos) {
    if(mask == (1<<n) - 1) {
        return cost[pos][0];
    }

    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for(int i = 0; i < n; i++) {
        if((mask & (1<<i)) == 0) {
            int newAns = cost[pos][i] + solve(mask | (1<<i), i);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    int res = solve(1, 0);
    cout << res;

    return 0;
}