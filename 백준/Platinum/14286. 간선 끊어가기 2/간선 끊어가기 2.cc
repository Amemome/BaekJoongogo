#include<bits/stdc++.h>

using namespace std;

int c[501][501], f[501][501]; 
int MaxFlow(int source,int sink) {
    int totalFlow = 0;
    while(true) {
        vector<int> parent(501,-1);
        queue<int> Q; parent[source] = source; Q.push(source);
        while(!Q.empty() && parent[sink] == -1) {
            int here = Q.front(); Q.pop();
            for(int t_here = 0; t_here < 501; t_here++) {
                if(c[here][t_here] - f[here][t_here] > 0 && parent[t_here] == -1) {
                    Q.push(t_here); parent[t_here] = here; } } }
        if(parent[sink] == -1) break;
        int amount = INT_MAX;
        for(int p = sink; p != source; p = parent[p])
            amount = min(c[parent[p]][p]-f[parent[p]][p],amount);
        for(int p = sink; p != source; p = parent[p]) {
            f[parent[p]][p] += amount; f[p][parent[p]] -= amount;
        }
        totalFlow += amount; }
    return totalFlow; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int cap,fr,to; cin >> fr >> to >> cap;
        c[fr][to] += cap; 
        c[to][fr] += cap; 
    } 

    int sin,sor; cin >> sin >> sor;
    cout << MaxFlow(sin,sor);
    return 0;
}
