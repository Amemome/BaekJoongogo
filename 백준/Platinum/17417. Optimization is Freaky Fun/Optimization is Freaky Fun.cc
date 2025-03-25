#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ps(ll n, ll s, ll e) {
    ll sum = 0, j = 0, i;
    for(i = s; i < (ll) sqrt(n); i++) {
        sum += n/i;
    } 
    i = 0;
    for(i = (ll) sqrt(n); i <= e; i=j+1) {
        j = n/(n/i);
        sum += n/i*(j-i+1);
    }
    if(j > e) {
        sum -= (n/e) * (j-e);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q; cin >> q;

    
    while(q--) {
        ll n,s,e; cin >> n >> s >> e;
        cout << ps(n,s,e) << '\n';
    }

}


