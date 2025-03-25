<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

#define MXN 6500
int A[MXN], B[MXN]; 
vector<vector<int>> adj(MXN);
bool visited[MXN];

int dx[6] = {1,0,-1,1,0,-1};
int dy[6] = {1,1,1,-1,-1,-1};

bool dfs(int a) {
    visited[a]=true;
    for(int b : adj[a]){
        if(B[b]==-1||!visited[B[b]]&&dfs(B[b])) {
            A[a]=b;B[b]=a;return true;
        }}
    return false;}

int main() {
	int tt; cin >> tt;
	while(tt--){
		fill(visited,visited+6500,0);
		for(int i = 0; i < 6500; i++) adj[i].clear();
		int n,m; cin >> n >> m;
		int cnt = 0;
		char board[81][81];
		for(int i=0; i<n;i++){
			string s; cin >> s;
			for(int j=0; j<m;j++){
				board[i][j] = s[j];
				if(s[j] == '.') cnt++;
			}
		}  //A는 왼쪽,B는오른쪽
		for(int y = 1; y < m; y+=2) {
			for(int x = 0; x < n; x++) {			
				if(board[x][y] == '.') {
					for(int d = 0; d < 6; d++) {
						int nx = x + dx[d]; 
						int ny = y + dy[d];
						if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if(board[nx][ny] == 'x') continue;
						adj[80*x+y].push_back(80*nx+ny);
					}
				}
			}
		}
		fill(A,A+6500,-1); fill(B,B+6500,-1);
		int match = 0;
		while(true) {
			bool flow = false;
			fill(visited,visited+MXN,false);
			for(int i=0;i < MXN;i++){
				if(A[i]==-1){
					if(dfs(i)){
						flow=true; match++;
					}
				}
			}
			if(!flow) break;
		}
		cout<<cnt-match << endl;
	}
=======
#include <bits/stdc++.h>
using namespace std;

#define MXN 6500
int A[MXN], B[MXN]; 
vector<vector<int>> adj(MXN);
bool visited[MXN];

int dx[6] = {1,0,-1,1,0,-1};
int dy[6] = {1,1,1,-1,-1,-1};

bool dfs(int a) {
    visited[a]=true;
    for(int b : adj[a]){
        if(B[b]==-1||!visited[B[b]]&&dfs(B[b])) {
            A[a]=b;B[b]=a;return true;
        }}
    return false;}

int main() {
	int tt; cin >> tt;
	while(tt--){
		fill(visited,visited+6500,0);
		for(int i = 0; i < 6500; i++) adj[i].clear();
		int n,m; cin >> n >> m;
		int cnt = 0;
		char board[81][81];
		for(int i=0; i<n;i++){
			string s; cin >> s;
			for(int j=0; j<m;j++){
				board[i][j] = s[j];
				if(s[j] == '.') cnt++;
			}
		}  //A는 왼쪽,B는오른쪽
		for(int y = 1; y < m; y+=2) {
			for(int x = 0; x < n; x++) {			
				if(board[x][y] == '.') {
					for(int d = 0; d < 6; d++) {
						int nx = x + dx[d]; 
						int ny = y + dy[d];
						if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if(board[nx][ny] == 'x') continue;
						adj[80*x+y].push_back(80*nx+ny);
					}
				}
			}
		}
		fill(A,A+6500,-1); fill(B,B+6500,-1);
		int match = 0;
		while(true) {
			bool flow = false;
			fill(visited,visited+MXN,false);
			for(int i=0;i < MXN;i++){
				if(A[i]==-1){
					if(dfs(i)){
						flow=true; match++;
					}
				}
			}
			if(!flow) break;
		}
		cout<<cnt-match << endl;
	}
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}