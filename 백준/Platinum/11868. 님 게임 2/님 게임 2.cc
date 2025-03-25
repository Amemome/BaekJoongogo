#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<ll> dol(n+1);
    for(int i = 0; i < n; i++) cin >> dol[i];
    ll result = 0;
    for(int i = 0; i < n; i++) {
        result = (result^(ll)dol[i]);
    } 
    if(result) {
        cout << "koosaga";
    } else {
        cout << "cubelover";
    }
}