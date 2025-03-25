#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

int c[210][210], f[210][210]; 

int MaxFlow(int source,int sink) {
    int totalFlow = 0;
    while(true) {
        vector<int> parent(210,-1);
        queue<int> Q; parent[source] = source; Q.push(source);
        while(!Q.empty() && parent[sink] == -1) {
            int here = Q.front(); Q.pop();
            for(int t_here = 0; t_here < 210; t_here++) {
                if(c[here][t_here] - f[here][t_here] > 0 && parent[t_here] == -1) {
                    Q.push(t_here); parent[t_here] = here;
                }
            }
        }
        if(parent[sink] == -1) break;
        int amount = INT_MAX;
        for(int p = sink; p != source; p = parent[p])
            amount = min(c[parent[p]][p]-f[parent[p]][p],amount);
        for(int p = sink; p != source; p = parent[p]) {
            f[parent[p]][p] += amount; f[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int tt; cin >> tt;
        c[0][i] += tt;
    }
    for(int i = 101; i <= m+100; i++) {
        int tt; cin >> tt;
        c[i][201] += tt;
    }

    for(int M = 101; M <= m+100; M++) {
        for(int N = 1; N <= n; N++) {
            int cap; cin >> cap;
            c[N][M] += cap;
        }
    }


    cout << MaxFlow(0,201);


    return 0;
}
