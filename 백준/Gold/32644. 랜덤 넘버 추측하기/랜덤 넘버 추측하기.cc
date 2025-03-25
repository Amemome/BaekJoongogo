<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void init(vector<ll> &a,vector<ll>&tree,int node,int start,int end) {
    if(start == end) 
        tree[node] = a[start];
    else {
        init(a,tree,node*2,start,(start+end)/2);
        init(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node] = tree[node*2]+tree[node*2+1];
    }
}
void update(vector<ll> &a,vector<ll>&tree,int node,int start,int end,int index,ll val) {
    if(index < start || index > end) return;
    if(start == end) {
        a[index] = val; tree[node] = val; return;
    }
    update(a,tree,node*2,start,(start+end)/2,index,val);
    update(a,tree,node*2+1,(start+end)/2+1,end,index,val);
    tree[node] = tree[node*2]+tree[node*2+1];
}
ll query(vector<ll> &a,vector<ll>&tree,int node,int start,int end,int left,int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    ll Lsum = query(a,tree,node*2,start,(start+end)/2,left,right);
    ll Rsum = query(a,tree,node*2+1,(start+end)/2+1,end,left,right);
    return Lsum + Rsum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;
    vector<ll> a(n);
    vector<ll> k(m);
    vector<ll> tree(n*4);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> k[i];
    init(a, tree, 1, 0, n-1);

    for(auto x : k) {
        cout << query(a,tree,1,0,n-1,0,x-1) << ' ';
        update(a,tree,1,0,n-1,x-1,0);
    }

}


=======
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void init(vector<ll> &a,vector<ll>&tree,int node,int start,int end) {
    if(start == end) 
        tree[node] = a[start];
    else {
        init(a,tree,node*2,start,(start+end)/2);
        init(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node] = tree[node*2]+tree[node*2+1];
    }
}
void update(vector<ll> &a,vector<ll>&tree,int node,int start,int end,int index,ll val) {
    if(index < start || index > end) return;
    if(start == end) {
        a[index] = val; tree[node] = val; return;
    }
    update(a,tree,node*2,start,(start+end)/2,index,val);
    update(a,tree,node*2+1,(start+end)/2+1,end,index,val);
    tree[node] = tree[node*2]+tree[node*2+1];
}
ll query(vector<ll> &a,vector<ll>&tree,int node,int start,int end,int left,int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    ll Lsum = query(a,tree,node*2,start,(start+end)/2,left,right);
    ll Rsum = query(a,tree,node*2+1,(start+end)/2+1,end,left,right);
    return Lsum + Rsum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;
    vector<ll> a(n);
    vector<ll> k(m);
    vector<ll> tree(n*4);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> k[i];
    init(a, tree, 1, 0, n-1);

    for(auto x : k) {
        cout << query(a,tree,1,0,n-1,0,x-1) << ' ';
        update(a,tree,1,0,n-1,x-1,0);
    }

}


>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
