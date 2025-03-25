#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll binary_gcd(ll a,ll b) { //큰 수에 대해서 사용.
    if(a==0||b==0) return a+b;
    int shift = __builtin_ctzll(a|b);
    a >>= __builtin_ctzll(a);
    while(b != 0) {
        b >>= __builtin_ctzll(b);
        if(a>b) swap(a,b); b-=a;
    }
    return a << shift;
}

struct egcdResult {
    ll gcd,x,y;
};
egcdResult egcd(ll a,ll b) {
    if(b==0) {
        return {a,1,0};
    }
    egcdResult res = egcd(b,a%b);
    ll x = res.y;
    ll y = res.x - (a/b) * res.y;
    return {res.gcd,x,y};
}

ll mod(ll a,ll m) {return (a % m + m) % m;}

ll crt(ll a1, ll m1,ll a2, ll m2) {
    ll g = gcd(m1,m2) , m = m1 / g * m2;
    if((a2 - a1) % g) return -1;//crt의 해가 존재X
    ll md = m2/g, s = mod((a2-a1)/g,m2/g);
    ll t = mod(egcd(m1/g%md,m2/g).x ,md);
    return a1 + s * t % md * m1;
}
//square free : i=1..sqrtN mu(i)floor(n/(i^2))
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n; cin >> n;
    while(n--) {
        int a,b,c,d; cin >> a>>b>>c>>d;
        cout << crt(c,a,d,b) << '\n';
    }

    
    
    return 0;
}