#include<bits/stdc++.h>
using namespace std;

int n , m;
vector<vector<int>> adj(101);



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
    cin >> n >> m;

	while(m--) {
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int result = 0; 
	queue<int> Q;
	vector<int> visited(n+1,0);
	Q.push(1);
	visited[1] = true;
	while(!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for(auto c : adj[cur]) {
			if(visited[c]) continue;
			Q.push(c);
			visited[c] = true;
			result++;
		}
	}

	cout << result;

    
    
    return 0;
}
