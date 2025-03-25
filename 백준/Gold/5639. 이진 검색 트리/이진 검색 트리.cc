<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

vector<int> tree(10010);

// 50 30 24 5 28 45 98 52 60
//
// 50 
// 30 24 5 28 45 
// 98 52 60

// 50
// 30
// 24 5 28
// 45

void srch(int start, int end) {
    if(start >= end) {
        return;
    }
    auto it = lower_bound(tree.begin()+start+1,tree.begin()+end,tree[start]);

    srch(start+1,it-tree.begin());
    srch(it-tree.begin(),end);
    cout << tree[start] << '\n';

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int idx = 0;
    while(cin >> tree[idx++]);
    idx--;
    
    srch(0,idx);
=======
#include <bits/stdc++.h>

using namespace std;

vector<int> tree(10010);

// 50 30 24 5 28 45 98 52 60
//
// 50 
// 30 24 5 28 45 
// 98 52 60

// 50
// 30
// 24 5 28
// 45

void srch(int start, int end) {
    if(start >= end) {
        return;
    }
    auto it = lower_bound(tree.begin()+start+1,tree.begin()+end,tree[start]);

    srch(start+1,it-tree.begin());
    srch(it-tree.begin(),end);
    cout << tree[start] << '\n';

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int idx = 0;
    while(cin >> tree[idx++]);
    idx--;
    
    srch(0,idx);
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}