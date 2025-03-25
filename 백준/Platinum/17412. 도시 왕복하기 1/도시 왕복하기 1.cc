<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

int c[401][401], f[401][401]; 
int MaxFlow(int source,int sink) {
    int totalFlow = 0;
    while(true) {
        vector<int> parent(401,-1);
        queue<int> Q; parent[source] = source; Q.push(source);
        while(!Q.empty() && parent[sink] == -1) {
            int here = Q.front(); Q.pop();
            for(int t_here = 0; t_here < 401; t_here++) {
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
    int n,p; cin >> n >> p;
    for(int i = 0; i < p; i++) {
        int fr,to ; cin >> fr >> to;
        c[fr][to] += 1; //간선마다용량추가
        } //시작과끝노드지정
    cout << MaxFlow(1,2);
    return 0;
}
=======
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

int c[401][401], f[401][401]; 
int MaxFlow(int source,int sink) {
    int totalFlow = 0;
    while(true) {
        vector<int> parent(401,-1);
        queue<int> Q; parent[source] = source; Q.push(source);
        while(!Q.empty() && parent[sink] == -1) {
            int here = Q.front(); Q.pop();
            for(int t_here = 0; t_here < 401; t_here++) {
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
    int n,p; cin >> n >> p;
    for(int i = 0; i < p; i++) {
        int fr,to ; cin >> fr >> to;
        c[fr][to] += 1; //간선마다용량추가
        } //시작과끝노드지정
    cout << MaxFlow(1,2);
    return 0;
}
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
