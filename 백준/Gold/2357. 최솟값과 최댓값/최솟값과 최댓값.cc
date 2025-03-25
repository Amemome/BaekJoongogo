#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void init1(vector<ll> &a,vector<ll>&tree,int node,int start,int end) {
    if(start == end) 
        tree[node] = a[start];
    else {
        init1(a,tree,node*2,start,(start+end)/2);
        init1(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node] = min(tree[node*2],tree[node*2+1]);
    }
}
ll query1(vector<ll>&tree,int node,int start,int end,int left,int right) {
    if(left > end || right < start) return INT_MAX;
    if(left <= start && end <= right) return tree[node];
    ll Lsum = query1(tree,node*2,start,(start+end)/2,left,right);
    ll Rsum = query1(tree,node*2+1,(start+end)/2+1,end,left,right);
    return min(Lsum , Rsum);
}
void init2(vector<ll> &a,vector<ll>&tree,int node,int start,int end) {
    if(start == end) 
        tree[node] = a[start];
    else {
        init2(a,tree,node*2,start,(start+end)/2);
        init2(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node] = max(tree[node*2],tree[node*2+1]);
    }
}
ll query2(vector<ll>&tree,int node,int start,int end,int left,int right) {
    if(left > end || right < start) return INT_MIN;
    if(left <= start && end <= right) return tree[node];
    ll Lsum = query2(tree,node*2,start,(start+end)/2,left,right);
    ll Rsum = query2(tree,node*2+1,(start+end)/2+1,end,left,right);
    return max(Lsum , Rsum);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;
    vector<ll> arr(n);
    vector<ll> tree1(n*4);
    vector<ll> tree2(n*4);
    for(int i = 0; i < n; i++) cin >> arr[i];

    init1(arr, tree1, 1, 0, n-1);
    init2(arr, tree2, 1, 0, n-1);

    for(int i = 0; i < m; i++) {
        int x,y; cin >> x >> y ;
        if(x>y) swap(x,y);
        cout << query1(tree1,1,0,n-1,x-1,y-1) << ' ' << query2(tree2,1,0,n-1,x-1,y-1) << '\n';
        
    }

}


