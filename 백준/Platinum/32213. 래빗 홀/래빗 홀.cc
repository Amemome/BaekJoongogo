#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

   
/*
    4 5  7 1
1 4 5
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        int result = 0;
        for(int i = 0; i < n; i++) {
            int k; cin >> k;
            result ^= k;
        }
        bool gg = (n-1) % 2;
        
        if (result ^ gg != 0) {
            cout << "eerste";
        } else {
            cout << "tweede";
        }
        cout << '\n';
    }
}

