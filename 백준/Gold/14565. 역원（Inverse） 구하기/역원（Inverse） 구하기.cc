<<<<<<< HEAD
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

    long long n,a;
    cin >> n >> a;

    cout << n - a << ' ';

    if(__gcd(n,a) == 1) {
        ll x,y;
        ll gcd = egcd(n,a,x,y);

        if(y < 0) y = n+y;
        cout << y;

    } else {
        cout << -1;
    }

    
    return 0;
=======
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

    long long n,a;
    cin >> n >> a;

    cout << n - a << ' ';

    if(__gcd(n,a) == 1) {
        ll x,y;
        ll gcd = egcd(n,a,x,y);

        if(y < 0) y = n+y;
        cout << y;

    } else {
        cout << -1;
    }

    
    return 0;
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}