#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007

typedef long long ll;

ll egcd(ll a,ll b,ll &x,ll &y) {
    if(b==0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1,y1;
    ll gcd = egcd(b,a%b,x1,y1);
    x = y1;
    y = x1 - (a/b) * y1;

    return gcd;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) {
        long long n,a;
        cin >> n >> a;
        if(__gcd(n,a) != 1) {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        ll x,y;
        egcd(n,a,x,y);

        if(x>0) x = x-a; //음수로 만들어버려
        ll result = ((-x*n)+1) / a;

        if(a==1) {
            result = n+1;
        } 
        if(result > 1000000000) {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        cout << result << '\n';
    }



    

    
    return 0;
}