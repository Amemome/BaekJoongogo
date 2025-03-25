<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
vector<int> prime(2001,1);

/*
N 이 50
숫자는 1000 이하

둘아 합해서 소수 (요소가 다를때) 는 짝 + 홀 이므로
짝이랑 홀 의 이분그래프르 만들어주면 됨.
*/
#define MXM 1001

bool dfs(int a,vector<int> &A,vector<int> &B,vector<vector<int>> &adj,bool visited[]) {
	visited[a] = true;
	for(int b : adj[a]) {
		if(B[b]==-1 || !visited[B[b]]&&dfs(B[b],A,B,adj,visited)) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}



void sieve() {
	prime[0] = prime[1] = false;
	for(int i = 2; i * i < 2001; i++) {
		if(prime[i]) {
			for(int j = 2*i; j < 2001; j+=i) {
				prime[j] = false;
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	sieve();
	vector<int> result; // 결과들을 저장.

    int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	for(int i = 1; i < n; i++) {
		if(!prime[arr[0]+arr[i]]) continue; //소수가 아닐때는 패스 
		//처음이랑 i 번이랑 매칭한 경우, 나머지 수가 최대매칭임을 보기

		
		vector<vector<int>> adj(MXM);
		bool visited[MXM];

		vector<int> odd;
		vector<int> even;

		for(int j = 1; j < n; j++) {
			if(j==i) continue;
			if(arr[j] % 2) odd.push_back(arr[j]);        
			else even.push_back(arr[j]);              
		}

		for(auto o : odd) {
			for(auto e : even) {
				if(prime[o+e]) adj[o].push_back(e);
			}
		}

		vector<int> A(MXM,-1);
		vector<int> B(MXM,-1);
		int match = 0;
		while(true) {
			bool flow = false;
			fill(visited,visited+MXM,false);
			for(int j = 0; j < MXM; j++) {
				if(A[j]==-1) {
					if(dfs(j,A,B,adj,visited)) {
						flow=true; match++;
					}
				}
			}
			if(!flow) break;
		}
		if(match == (n/2)-1) result.push_back(arr[i]);

	}
	sort(result.begin(),result.end());
	if(result.size()==0) cout << -1;
	else for(auto x : result) cout << x << ' ';
    
    return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
vector<int> prime(2001,1);

/*
N 이 50
숫자는 1000 이하

둘아 합해서 소수 (요소가 다를때) 는 짝 + 홀 이므로
짝이랑 홀 의 이분그래프르 만들어주면 됨.
*/
#define MXM 1001

bool dfs(int a,vector<int> &A,vector<int> &B,vector<vector<int>> &adj,bool visited[]) {
	visited[a] = true;
	for(int b : adj[a]) {
		if(B[b]==-1 || !visited[B[b]]&&dfs(B[b],A,B,adj,visited)) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}



void sieve() {
	prime[0] = prime[1] = false;
	for(int i = 2; i * i < 2001; i++) {
		if(prime[i]) {
			for(int j = 2*i; j < 2001; j+=i) {
				prime[j] = false;
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	sieve();
	vector<int> result; // 결과들을 저장.

    int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	for(int i = 1; i < n; i++) {
		if(!prime[arr[0]+arr[i]]) continue; //소수가 아닐때는 패스 
		//처음이랑 i 번이랑 매칭한 경우, 나머지 수가 최대매칭임을 보기

		
		vector<vector<int>> adj(MXM);
		bool visited[MXM];

		vector<int> odd;
		vector<int> even;

		for(int j = 1; j < n; j++) {
			if(j==i) continue;
			if(arr[j] % 2) odd.push_back(arr[j]);        
			else even.push_back(arr[j]);              
		}

		for(auto o : odd) {
			for(auto e : even) {
				if(prime[o+e]) adj[o].push_back(e);
			}
		}

		vector<int> A(MXM,-1);
		vector<int> B(MXM,-1);
		int match = 0;
		while(true) {
			bool flow = false;
			fill(visited,visited+MXM,false);
			for(int j = 0; j < MXM; j++) {
				if(A[j]==-1) {
					if(dfs(j,A,B,adj,visited)) {
						flow=true; match++;
					}
				}
			}
			if(!flow) break;
		}
		if(match == (n/2)-1) result.push_back(arr[i]);

	}
	sort(result.begin(),result.end());
	if(result.size()==0) cout << -1;
	else for(auto x : result) cout << x << ' ';
    
    return 0;
}
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
