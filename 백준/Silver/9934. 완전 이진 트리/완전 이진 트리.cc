#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> tree(pow(2,11));
vector<int> a(pow(2,11));
int Index = 1;

void search(int node) {
    if(node >= pow(2,n)) {
        return;
    }
    search(node*2);
    tree[node] = a[Index++];
    search(node*2+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i = 1; i < pow(2,n); i++) {
        cin >> a[i];
    }
    search(1);

    for(int i = 1; i < pow(2,n); (i<<=1)) {
        for(int j = i; j < (i<<1); j++) {
            cout << tree[j] << ' ';
        }
        cout << '\n';
    }
    
}