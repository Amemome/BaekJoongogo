<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

#define MXN 2001
int A[MXN], B[MXN]; 
vector<int> adj[MXN]; bool visited[MXN];
bool dfs(int a) {
    visited[a]=true;
    for(int b : adj[a]){
        if(B[b]==-1||!visited[B[b]]&&dfs(B[b])) {
            A[a]=b;B[b]=a;return true;
        }}
    return false;}
int main() {
    int n,m; cin >> n >> m; n *= 2;
    for(int i=0; i<n;i+=2){
        int s; cin >> s;
        for(int j=0; j<s;j++){
            int z; cin >> z;
            adj[i].push_back(z-1);
            adj[i+1].push_back(z-1);
        }
    }//A는 왼쪽,B는오른쪽
    fill(A,A+n,-1); fill(B,B+m,-1);
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
=======
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

#define MXN 2001
int A[MXN], B[MXN]; 
vector<int> adj[MXN]; bool visited[MXN];
bool dfs(int a) {
    visited[a]=true;
    for(int b : adj[a]){
        if(B[b]==-1||!visited[B[b]]&&dfs(B[b])) {
            A[a]=b;B[b]=a;return true;
        }}
    return false;}
int main() {
    int n,m; cin >> n >> m; n *= 2;
    for(int i=0; i<n;i+=2){
        int s; cin >> s;
        for(int j=0; j<s;j++){
            int z; cin >> z;
            adj[i].push_back(z-1);
            adj[i+1].push_back(z-1);
        }
    }//A는 왼쪽,B는오른쪽
    fill(A,A+n,-1); fill(B,B+m,-1);
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
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
