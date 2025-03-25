<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum = 0;


vector<int> arr(40);
vector<ll> leftset,rightset;
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
    
    int n,s; cin >> n >> s;
    ll result = 0;
    for(int i = 0; i < n; i++) cin >> arr[i];

    dfs(0,n/2,leftset,0);
    dfs(n/2,n,rightset,0);
    
    sort(rightset.begin(),rightset.end());

    for(int x : leftset) {
        result += upper_bound(rightset.begin(),rightset.end(),s-x) - lower_bound(rightset.begin(),rightset.end(),s-x);
    }
    if(s==0) result--;
    cout << result;
}


=======
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum = 0;


vector<int> arr(40);
vector<ll> leftset,rightset;
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
    
    int n,s; cin >> n >> s;
    ll result = 0;
    for(int i = 0; i < n; i++) cin >> arr[i];

    dfs(0,n/2,leftset,0);
    dfs(n/2,n,rightset,0);
    
    sort(rightset.begin(),rightset.end());

    for(int x : leftset) {
        result += upper_bound(rightset.begin(),rightset.end(),s-x) - lower_bound(rightset.begin(),rightset.end(),s-x);
    }
    if(s==0) result--;
    cout << result;
}


>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
