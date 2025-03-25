<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> Edge; // {가중치, {정점1, 정점2}}
vector<int> parent, rankArr;
// Union-Find 초기화
void initialize(int n) {
    parent.resize(n + 1);
    rankArr.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
} // Find 연산: 경로 압축 적용
int find(int u) {
    if (u != parent[u])
        parent[u] = find(parent[u]); // 경로 압축
    return parent[u];
} // Union 연산: 랭크 기반 병합 적용
void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (rankArr[u] < rankArr[v])
            swap(u, v);
        parent[v] = u;
        if (rankArr[u] == rankArr[v])
            rankArr[u]++;}}
int kruskalMST(int n, priority_queue<Edge, vector<Edge>, greater<Edge>> &pq) {
    initialize(n); // Union-Find 초기화
    int mst_weight = 0;
    int edges_used = 0;
    while (!pq.empty() && edges_used < n - 1) {
        auto [weight, endpoints] = pq.top(); pq.pop();
        int u = endpoints.first;
        int v = endpoints.second; // 두 정점이 서로 다른 집합에 있을 때만 간선을 추가
        if (find(u) != find(v)) {
            unite(u, v);
            mst_weight += weight;
            edges_used++;
        }
    }
    return mst_weight;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    initialize(n);
    for (int i = 0; i < m; i++) {
        int q,u,v; cin >> q >> u >> v;
        if(q) {
            if(find(u)==find(v)) cout << "YES";
            else cout << "NO";
            cout << "\n";
        } else {
            unite(u,v);
        }
    }

}
=======
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> Edge; // {가중치, {정점1, 정점2}}
vector<int> parent, rankArr;
// Union-Find 초기화
void initialize(int n) {
    parent.resize(n + 1);
    rankArr.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
} // Find 연산: 경로 압축 적용
int find(int u) {
    if (u != parent[u])
        parent[u] = find(parent[u]); // 경로 압축
    return parent[u];
} // Union 연산: 랭크 기반 병합 적용
void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (rankArr[u] < rankArr[v])
            swap(u, v);
        parent[v] = u;
        if (rankArr[u] == rankArr[v])
            rankArr[u]++;}}
int kruskalMST(int n, priority_queue<Edge, vector<Edge>, greater<Edge>> &pq) {
    initialize(n); // Union-Find 초기화
    int mst_weight = 0;
    int edges_used = 0;
    while (!pq.empty() && edges_used < n - 1) {
        auto [weight, endpoints] = pq.top(); pq.pop();
        int u = endpoints.first;
        int v = endpoints.second; // 두 정점이 서로 다른 집합에 있을 때만 간선을 추가
        if (find(u) != find(v)) {
            unite(u, v);
            mst_weight += weight;
            edges_used++;
        }
    }
    return mst_weight;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    initialize(n);
    for (int i = 0; i < m; i++) {
        int q,u,v; cin >> q >> u >> v;
        if(q) {
            if(find(u)==find(v)) cout << "YES";
            else cout << "NO";
            cout << "\n";
        } else {
            unite(u,v);
        }
    }

}
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
