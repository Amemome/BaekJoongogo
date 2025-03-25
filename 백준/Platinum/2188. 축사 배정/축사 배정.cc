#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

int A[401], B[401]; 
vector<int> adj[401]; bool visited[401];
bool dfs(int a) {
    visited[a]=true;
    for(int b : adj[a]){
        if(B[b]==-1||!visited[B[b]]&&dfs(B[b])) {
            A[a]=b;B[b]=a;return true;
        }
    }
    return false;
}

int main() {
    int n,m; cin >> n >> m;
    for(int i=0; i<n;i++){
        int s; cin >> s;
        for(int j=0; j<s;j++){
            int z; cin >> z;
            adj[i].push_back(z-1);
        }
    }
    fill(A,A+n,-1);
    fill(B,B+m,-1);
    int match = 0;
    while(true) {
        bool flow = false;
        fill(visited,visited+n,false);
        for(int i=0;i < n;i++){
            if(A[i]==-1){
                if(dfs(i)){
                    flow=true; match++;
                }
            }
        }
        if(!flow) break;
    }

    cout<<match;
}
