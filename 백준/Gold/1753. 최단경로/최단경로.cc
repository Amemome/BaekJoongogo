#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int v,e,st; 
vector<pair<int,int>> adj[20005];
int d[20005];
const int INF = INT_MAX;

int dike(int start,int end) {
    fill(d,d+v+1,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    d[start] = 0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto [dist,cur] = pq.top(); pq.pop();
        if(d[cur] != dist) continue;
        for(auto[w,nxt] : adj[cur]) {
            if(d[nxt] > d[cur] + w) {
                d[nxt] = d[cur] + w;
                pq.push({d[nxt],nxt});
            }
        }
    }
    return d[end];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e >> st;
    while(e--) {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    dike(st,2);
    for(int i = 1; i <= v; i++) {
        if(d[i] == INF) cout << "INF";
        else cout << d[i];
        cout << '\n';
    }

}
