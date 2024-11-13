#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll result = 0;
    for(int i = 2; i <=n; i++ ) {
        result += (n/i-1)*i;
        result %= 1000000;
    }
    cout << result;

}


