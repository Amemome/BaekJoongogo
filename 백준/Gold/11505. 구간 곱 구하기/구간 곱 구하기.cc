<<<<<<< HEAD
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

/*
쿼리 어케 했더라 
*/

void init(vector<long long> & arr, vector<long long> & tree,int node,int first,int end) {
    if(first == end) {
        tree[node] = arr[first];
        return;
    }
    init(arr,tree,node*2,first,(first+end)/2);
    init(arr,tree,node*2+1,(first+end)/2+1,end);
    tree[node] = (tree[node*2] * tree[node*2+1]) % mod;
}

long long query(vector<long long> & arr, vector<long long> & tree,int node,int first,int end,int left,int right) {
    if(right < first|| end < left) { //포함X 이면 리턴
        return 1;
    }
    if(left <= first && end <= right) {
        return tree[node];
    }

    long long lsum = query(arr,tree,node*2,first,(first+end)/2,left,right);
    long long rsum = query(arr,tree,node*2+1,(first+end)/2+1,end,left,right);
    return lsum * rsum % mod;
}

void Update(vector<long long> & arr, vector<long long> & tree,int node,int first,int end,int index,int value) {
    if(index < first || end < index) return;
    if(first == end) {
        arr[index] = value;
        tree[node] = value;
        return;
    }
    Update(arr,tree,node*2,first,(first+end)/2,index,value);
    Update(arr,tree,node*2+1,(first+end)/2+1,end,index,value);
    tree[node] = (tree[node*2] * tree[node*2+1]) % mod;
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m,k; cin >> n >> m >> k;

    vector<long long> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int T_size = ceil(log2(n));
    vector<long long> tree((1<<T_size+1)+1);

    init(arr,tree,1,0,n-1);

    for(int i = 0; i < m+k; i++) {
        long long b , c;
        int q; 
        cin >> q >> b >> c;
        if(q == 1) {
            Update(arr,tree,1,0,n-1,b-1,c);
        } else {
            cout << query(arr,tree,1,0,n-1,b-1,c-1) << '\n';
        }
    }


    return 0;
=======
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

/*
쿼리 어케 했더라 
*/

void init(vector<long long> & arr, vector<long long> & tree,int node,int first,int end) {
    if(first == end) {
        tree[node] = arr[first];
        return;
    }
    init(arr,tree,node*2,first,(first+end)/2);
    init(arr,tree,node*2+1,(first+end)/2+1,end);
    tree[node] = (tree[node*2] * tree[node*2+1]) % mod;
}

long long query(vector<long long> & arr, vector<long long> & tree,int node,int first,int end,int left,int right) {
    if(right < first|| end < left) { //포함X 이면 리턴
        return 1;
    }
    if(left <= first && end <= right) {
        return tree[node];
    }

    long long lsum = query(arr,tree,node*2,first,(first+end)/2,left,right);
    long long rsum = query(arr,tree,node*2+1,(first+end)/2+1,end,left,right);
    return lsum * rsum % mod;
}

void Update(vector<long long> & arr, vector<long long> & tree,int node,int first,int end,int index,int value) {
    if(index < first || end < index) return;
    if(first == end) {
        arr[index] = value;
        tree[node] = value;
        return;
    }
    Update(arr,tree,node*2,first,(first+end)/2,index,value);
    Update(arr,tree,node*2+1,(first+end)/2+1,end,index,value);
    tree[node] = (tree[node*2] * tree[node*2+1]) % mod;
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m,k; cin >> n >> m >> k;

    vector<long long> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int T_size = ceil(log2(n));
    vector<long long> tree((1<<T_size+1)+1);

    init(arr,tree,1,0,n-1);

    for(int i = 0; i < m+k; i++) {
        long long b , c;
        int q; 
        cin >> q >> b >> c;
        if(q == 1) {
            Update(arr,tree,1,0,n-1,b-1,c);
        } else {
            cout << query(arr,tree,1,0,n-1,b-1,c-1) << '\n';
        }
    }


    return 0;
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}