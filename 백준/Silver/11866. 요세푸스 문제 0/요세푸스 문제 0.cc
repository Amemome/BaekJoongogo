#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

   
/*
    4 5  7 1
1 4 5
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin >> n >> k;
    queue<int> Q;
    
    for(int i =1 ; i <= n; i++) Q.push(i);
    vector<int> res;
    int cnt = 0;
    while(!Q.empty()) {
        cnt++;
        if(cnt%k) {
        int tmp = Q.front(); Q.pop(); 
        Q.push(tmp); 
    } else {
        res.push_back(Q.front()); Q.pop(); 
    }
        
    }
    cout << "<";
    for(int i = 0; i < n-1;i++) cout << res[i]<<", ";
    cout << res[n-1]<<">";
}

