#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>

using namespace std;


/*
세그트리 ㄱㄱ혓
*/ 
//start 가 담당하는 배열 시작과 end 가 끝
void init(vector<long long> &a,vector<long long> &tree, int node ,int start, int end) {
    if (start == end) { //리프노드인경우.
        tree[node] = a[start]; //트리에다가 배열의 수를 저장해야함.
    } else { //재귀이기 때문에 구간을 좁혀간다.
        init(a,tree,node*2,start,(start+end)/2); //재귀를 사용하여 왼쪽과 오른쪽을 구해야함
        init(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node] = tree[node*2] + tree[node*2+1]; //왼쪽과 오른쪽 더해서 저장하기.
    }
}
/*
구간의 합 구하기. 구간 left, right 가 주어졋을 때, 합을 구하려면 트리를 루트부터 순회하면서
노드에 저장된 구간의 left, right 관계를 알아봐야 합니다. node 에 저장된 구간을 start,end
합을 구해야 하는 구간이 left,right 라면 4가지로 정해질 수 있다.

*/

/*
시간 복잡도 : 트리의 각 레벨(층) 에서 방문하는 노드의 개수가 4개를 넘지 않음. 이 말을 잘 이해 못햇
었는데, 그러니까 루트에서는 한번, 그 자식에서 2번 일어나고, 그 자식에서도 최대 4번이기 때문에 각 층(레벨)
에서 4번을 넘지 않는다는거임.

왜냐하면 ....
*/

/*

*/

long long query(vector<long long> &tree, int node, int start, int end,int left, int right ){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) {
        return tree[node];
    }
    long long lsum = query(tree,node*2,start,(start+end)/2,left,right);
    long long rsum = query(tree,node*2+1,(start+end)/2+1,end,left,right);
    return lsum + rsum;
}

void update(vector<long long> &a, vector<long long> &tree, int node,int start,int end,int index, long long val) {
    if(index < start || index > end) { //구간에 속하지 않음.
        return;
    }
    if(start == end) { //리프노드.
        a[index] = val;
        tree[node] = val;
        return;
    }
    update(a,tree,node*2,start,(start+end)/2,index,val);
    update(a,tree,node*2+1,(start+end)/2+1,end,index,val);
    tree[node] = tree[node*2] + tree[node*2+1];
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m,k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    int h = (int) ceil(log2(n));
    int tree_size = (1<<(h+1));
    vector<long long> tree(tree_size);

    for(int i = 0; i < n; i++) cin >> a[i];

    m = m+k;
    init(a,tree,1,0,n-1);
  
    while(m--) {
        int q;
        cin >> q;
        if(q == 1) {
            int index;
            long long value;
            cin >> index >> value ;
            update(a,tree,1,0,n-1,index-1,value);

        } else {
            int left,right;
            cin >> left >> right;
            cout << query(tree,1,0,n-1,left-1,right-1) << '\n';
        }
    }

    return 0;
}