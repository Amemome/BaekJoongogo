#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007

typedef long long ll;
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
/*
x === e mod 15
x === s mod 28
x === m mod 19

M = 15 * 28 * 19
=...m1   m2   m3

M1 = M / m1
M2 = M / m2
M3 = M / m3

M1y1 === 1 (mod m1) ~~ y1 구하기.
M1 mod m1 의 역원을 구해

e * y1 * M1

*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int e,s,m; cin >> e >> s >> m;

    int M = 15 * 28 * 19;

    long long result = 0;

    int M1 = M/15;
    int M2 = M/28;
    int M3 = M/19;
    int y1,y2,y3;
    egcdResult R1,R2,R3;
    R1 = egcd(M1,15);
    if(R1.x < 0) y1 = R1.x+15; else y1 = R1.x;
    R2 = egcd(M2,28);
    if(R2.x < 0) y2 = R2.x+28; else y2 = R2.x;
    R3 = egcd(M3,19);
    if(R3.x < 0) y3 = R3.x+19; else y3 = R3.x;

    result = e * y1 * M1 + s * y2 * M2 + m * y3 * M3;
    result %= M;
    cout << ((result == 0) ? 7980 : result);

    
    return 0;
}