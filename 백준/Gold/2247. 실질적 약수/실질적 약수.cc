#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n; 
    cin >> n;
    ll result = 0;
    ll j;
    for(int i = 2; i < n; i=j+1) {
        j = n/(n/i);
        ll sumitoj = (j+i)*(j-i+1)/2;
        result += (n/i-1)*sumitoj;
        result %= 1000000;
    }

    // result -= n*(n+1)/2 + (n-1);

    cout << result;
}


