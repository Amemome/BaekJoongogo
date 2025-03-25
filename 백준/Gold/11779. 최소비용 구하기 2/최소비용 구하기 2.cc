#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>> adj[1001];
int d[1001];
int pre[1001];
const int INF = INT_MAX;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int v,e,st,ed; cin >> v >> e;
    fill(d,d+v+1,INF);
    while(e--) {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    cin >> st >> ed;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    d[st] = 0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.second]!= cur.first) continue; //가중치가 같지 않음?
        for(auto nxt : adj[cur.second]) {
            if(d[nxt.second] <= d[cur.second] + nxt.first) continue;
            d[nxt.second] = d[cur.second] + nxt.first;
            pre[nxt.second] = cur.second;
            pq.push({d[nxt.second],nxt.second});
        }
    }
    cout << d[ed] << endl;
    vector<int> path;
    while(ed) {
        path.push_back(ed);
        ed = pre[ed];
    }
    cout << path.size() << endl;
    reverse(path.begin(),path.end());
    for(auto a : path) cout << a << ' ';

}
