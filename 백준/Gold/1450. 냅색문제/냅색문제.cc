#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<ll> arr(40);

void dfs(int s,int e,vector<ll>& Set,ll sum) {
    if(s==e) {
        Set.push_back(sum);
        return;
    }
    dfs(s+1,e,Set,sum);
    dfs(s+1,e,Set,sum+arr[s]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,c; cin >> n >> c;
    ll result = 0;
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<ll> leftset,rightset;
    dfs(0,n/2,leftset,0);
    dfs(n/2,n,rightset,0);
    
    sort(rightset.begin(),rightset.end());

    for(ll x : leftset) {
        result += upper_bound(rightset.begin(),rightset.end(),c-x) - rightset.begin();
    }
    cout << result;
    
}


