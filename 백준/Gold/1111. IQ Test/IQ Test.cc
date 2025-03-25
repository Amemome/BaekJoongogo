#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/*
-100~100 -> -100~100 이려면..
//100 * 1000000
*/

set<pair<int,int>> candidate;

void init(int x,int y) {
    for(int a = -200; a <= 200;  a++) {
        for(int b = -20000; b <= 20000; b++) {
            if((x*a+b) == y) candidate.insert({a,b});
        }
    }
}
void update(int x,int y) {
    set<pair<int,int>> newset;
    for(int a = -200; a <= 200;  a++) {
        for(int b = -20000; b <= 20000; b++) {
            if(((x*a+b) == y)
            && candidate.find({a,b}) != candidate.end()) newset.insert({a,b});
        }
    }
    swap(newset,candidate);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(n==1) {
        cout << "A";
        return 0;
    } else { //50 개.. 100000
        set<int> result;
        init(arr[0],arr[1]);
        for(int i = 1; i < n-1; i++) update(arr[i],arr[i+1]);
        for(auto x : candidate) result.insert(arr[n-1]*x.first+x.second);
        if(result.size() == 0) cout << "B";
        else if(result.size() > 1) cout << "A";
        else {
            cout << *(result.begin());
        }
    }

    

}

