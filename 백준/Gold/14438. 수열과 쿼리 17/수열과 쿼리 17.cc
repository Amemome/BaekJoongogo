#include <bits/stdc++.h>

using namespace std;
/*
길이가 N 인 수열이 주어진다.이때, 다음 쿼리를 수행하
q 1 Ai 를 v 로 바꿈.
q 2 i j  Ai ~ Aj 까지에서 크기가 가장 작은 값을 출력. 수열의 인덱스는 1 부터!
*/

void init(vector<long long> &a,vector<long long> &tree,int node,int start,int end) {
    if(start==end) {
        tree[node] = a[start];
    } else {
        init(a,tree,node*2,start,(start+end)/2);
        init(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node] = min(tree[node*2] , tree[node*2+1]);
    }
} 

long long query(vector<long long> &a,vector<long long> &tree,int node,int start,int end,int left, int right) {
    if(end < left || right < start) {
        return 1000000000;
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    long long lmin = query(a,tree,node*2,start,(start+end)/2,left,right);
    long long rmin = query(a,tree,node*2+1,(start+end)/2+1,end,left,right);
    return min(lmin,rmin);
}

void update(vector<long long> &a,vector<long long> &tree,int node,int start,int end,int index,long long value) {
    if(start > index || end < index) {
        return;
    }
    if(start == end) {
        tree[node] = value;
        a[index] = value;
        return;
    }
    update(a,tree,node*2,start,(start+end)/2,index,value);
    update(a,tree,node*2+1,(start+end)/2+1,end,index,value);
    tree[node] = min(tree[node*2] , tree[node*2+1]);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<long long> a(n);
    int h = ceil(log2(n));
    int treeSize = (1<<(h+1)); //2^h+1
    vector<long long> tree(treeSize);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    init(a,tree,1,0,n-1);
 
    
    int k; cin >> k;
    while(k--) {
        int q; cin >> q;
        if(q == 1) {
            int index;
            long long value;
            cin >> index >> value;
            update(a,tree,1,0,n-1,--index,value);

        } else {
            int index , jndex;
            cin >> index >> jndex;
            cout << query(a,tree,1,0,n-1,--index,--jndex) << '\n';

        }
    }

    return 0;

}