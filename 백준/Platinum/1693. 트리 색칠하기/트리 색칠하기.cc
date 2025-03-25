#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree(100001);
vector<int> visited(100001);
int dp[20][100001];
int n;

int dfs(int node,int color) {
    if(dp[color][node] != 0) return dp[color][node];
    visited[node] = true;

    dp[color][node] = color;
    
    for(auto c : tree[node]) {
        if(visited[c]) continue;
        int lm = INT_MAX;

        
        for(int i = 1; i < 20; i++) {
            if(i == color) continue;
            lm = min(dfs(c,i),lm); 
        }  
        dp[color][node] += lm;
    }
    visited[node] = false;
    return dp[color][node];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int u,v;
    for(int i = 0 ; i < n-1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int llm = INT_MAX;
    for(int i = 1; i < 20; i++) {
        llm = min(llm,dfs(1,i));
    }  

    cout << llm;

}