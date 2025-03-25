#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> tree(1000001);
int dp[2][1000001];
int visited[1000001];

void dfs(int n) {
    visited[n] = true;
    dp[0][n] = 0;
    dp[1][n] = 1;
    for(auto j : tree[n]) {
        if(visited[j]) continue;
        dfs(j);
        dp[0][n] += dp[1][j];
        dp[1][n] += min(dp[0][j],dp[1][j]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n; n--;
    while(n--) {
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1);

    cout << min(dp[0][1],dp[1][1]);

    return 0;
}