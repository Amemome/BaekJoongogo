#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int, int> Edge; // 가중치, 정점
vector<vector<Edge>> adj(1001);    // 인접 리스트

// start 노드를 시작으로 n개의 정점을 포함하는 MST
int primMST(int start, int n) { // 가중치가 작은 간선이 먼저 나오게 설정
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<bool> inMST(n + 1, false); // MST에 포함 여부를 나타냄
    int mst_weight = 0;

    pq.push({0, start}); // 시작 정점의 가중치 0
    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();
        
        if (inMST[u]) continue;  // 이미 MST에 포함된 경우 무시
        inMST[u] = true;
        mst_weight += weight;

        for (auto [v_weight, v] : adj[u]) {
            if (!inMST[v]) pq.push({v_weight, v});
        }
    }
    return mst_weight;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int result = primMST(1, n);
    cout << result;
}
