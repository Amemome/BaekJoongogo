<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_V 20000

struct Edge { // u -> v
    int v,cap,ref; //ref 는 역간선 ?
    Edge(int v,int cap,int ref) :v(v),cap(cap),ref(ref) {}
}; 

int S,T;
vector<vector<Edge>> edges; //그래프
vector<int> level, next_v; //레벨그래프, flow계산시 역추적 사용.
void init(int MAX) {
	edges.resize(MAX);
	level.resize(MAX);
	next_v.resize(MAX);
}


void addEdge(int u,int v,int cap,bool inv) {
	edges[u].emplace_back(v,cap,(int)edges[v].size());
	edges[v].emplace_back(u,inv?cap : 0, (int) edges[u].size()-1);
} //  이 간선의 역방향 간선이 v의 인접 리스트에서 어떤 위치에 있는지 저장.
void reset_next_v() {
	fill(next_v.begin(),next_v.end(),0);
}
bool bfs() {
	fill(level.begin(),level.end(),-1);
	queue<int> Q;
	level[S] = 0;
	Q.push(S);
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		for(auto edge: edges[u]) {
			int v = edge.v, cap = edge.cap;
			if(level[v]==-1 && cap > 0) {
				level[v] = level[u] + 1;
				Q.push(v);
			}
		}
	}
	return level[T] != -1;//sink T 에 도달가능여부.
}
int dfs(int u,int max_flow) {
	if(u==T) return max_flow; //싱크에 도달
	for(int &i = next_v[u]; i<edges[u].size(); i++) {
		int v = edges[u][i].v, cap = edges[u][i].cap;
		if(level[u]+1 == level[v] && cap > 0) { //level satisfy
			int flow = dfs(v,min(max_flow,cap));
			if(flow>0) {
				edges[u][i].cap -= flow;//유량갱신
				edges[v][edges[u][i].ref].cap += flow;//역간선용량증가
				return flow;
			}
		}
	}
	return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	init(20000);

	int n,m; cin >> n >> m;
	string s;

	for(int x = 0; x < n; x++) {
		for(int y = 0; y < m; y++) {
			if(y+1 < m) {
				addEdge(x*100+y+10000,x*100+(y+1),20000,false);
				addEdge(x*100+(y+1)+10000,x*100+(y),20000,false);
			}
			if(x+1 < n){
				addEdge(x*100+y+10000,(x+1)*100+y,20000,false);
				addEdge((x+1)*100+y+10000,(x)*100+y,20000,false);
			} 
		}
	}

	for(int x = 0; x < n; x++) {
		cin >> s;
		for(int y = 0; y < m; y++) {
			char c = s[y];
			if(c != '#') addEdge(x*100+y,x*100+y+10000,1,false);

			if(c == 'K') S = 100*x+y;
			else if(c == 'H') T = 100*x+y;
		}
	}

	if(abs(S-T) == 1 || abs(S-T) == 100) {
		cout << -1;
		return 0;
	}

    int result = 0;
    while(bfs()) {
        reset_next_v();
        while(true) {
            int flow = dfs(S+10000,INT_MAX);
            if(!flow) break;
            result += flow;
        }
    }
    cout << result;
=======
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_V 20000

struct Edge { // u -> v
    int v,cap,ref; //ref 는 역간선 ?
    Edge(int v,int cap,int ref) :v(v),cap(cap),ref(ref) {}
}; 

int S,T;
vector<vector<Edge>> edges; //그래프
vector<int> level, next_v; //레벨그래프, flow계산시 역추적 사용.
void init(int MAX) {
	edges.resize(MAX);
	level.resize(MAX);
	next_v.resize(MAX);
}


void addEdge(int u,int v,int cap,bool inv) {
	edges[u].emplace_back(v,cap,(int)edges[v].size());
	edges[v].emplace_back(u,inv?cap : 0, (int) edges[u].size()-1);
} //  이 간선의 역방향 간선이 v의 인접 리스트에서 어떤 위치에 있는지 저장.
void reset_next_v() {
	fill(next_v.begin(),next_v.end(),0);
}
bool bfs() {
	fill(level.begin(),level.end(),-1);
	queue<int> Q;
	level[S] = 0;
	Q.push(S);
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		for(auto edge: edges[u]) {
			int v = edge.v, cap = edge.cap;
			if(level[v]==-1 && cap > 0) {
				level[v] = level[u] + 1;
				Q.push(v);
			}
		}
	}
	return level[T] != -1;//sink T 에 도달가능여부.
}
int dfs(int u,int max_flow) {
	if(u==T) return max_flow; //싱크에 도달
	for(int &i = next_v[u]; i<edges[u].size(); i++) {
		int v = edges[u][i].v, cap = edges[u][i].cap;
		if(level[u]+1 == level[v] && cap > 0) { //level satisfy
			int flow = dfs(v,min(max_flow,cap));
			if(flow>0) {
				edges[u][i].cap -= flow;//유량갱신
				edges[v][edges[u][i].ref].cap += flow;//역간선용량증가
				return flow;
			}
		}
	}
	return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	init(20000);

	int n,m; cin >> n >> m;
	string s;

	for(int x = 0; x < n; x++) {
		for(int y = 0; y < m; y++) {
			if(y+1 < m) {
				addEdge(x*100+y+10000,x*100+(y+1),20000,false);
				addEdge(x*100+(y+1)+10000,x*100+(y),20000,false);
			}
			if(x+1 < n){
				addEdge(x*100+y+10000,(x+1)*100+y,20000,false);
				addEdge((x+1)*100+y+10000,(x)*100+y,20000,false);
			} 
		}
	}

	for(int x = 0; x < n; x++) {
		cin >> s;
		for(int y = 0; y < m; y++) {
			char c = s[y];
			if(c != '#') addEdge(x*100+y,x*100+y+10000,1,false);

			if(c == 'K') S = 100*x+y;
			else if(c == 'H') T = 100*x+y;
		}
	}

	if(abs(S-T) == 1 || abs(S-T) == 100) {
		cout << -1;
		return 0;
	}

    int result = 0;
    while(bfs()) {
        reset_next_v();
        while(true) {
            int flow = dfs(S+10000,INT_MAX);
            if(!flow) break;
            result += flow;
        }
    }
    cout << result;
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}