#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> health(100001);
vector<vector<int>> tree(100001);
vector<int> dp(100001);
vector<bool> visited(100001);
int cnt = 0;

void dfs(int node) {
    visited[node] = true;
    int sum = 0;
    vector<int> childsss;
    for(auto child : tree[node]) {
        if(!visited[child]) {
            dfs(child);
            childsss.push_back(dp[child]);
            sum += dp[child];
        }
    }
    sort(childsss.begin(),childsss.end(),greater<>());
    int idx = 0;
    while(sum+health[node] > k) {
        sum -= childsss[idx++];
        cnt++;
    }

    dp[node] = health[node] + sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k; //1-based index
    for(int i = 1; i <= n; i++) cin >> health[i];
    for(int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1);

    cout << cnt;
    
    
}