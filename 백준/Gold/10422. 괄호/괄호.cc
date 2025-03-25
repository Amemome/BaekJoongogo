<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
typedef long long ll;

ll dp[5001][5001];

//solve 에서 dp[d][k] 를 정의해준다.
void solve(int d,int k) {
    if(d == 0) {
        dp[d][k] = 1;
        return;
    }
    ll d1 = 0;
    ll k1 = 0;    

    if(dp[d-1][k+1] == 0) solve(d-1,k+1);

    d1 = dp[d-1][k+1];
    

    if(k>0) {
    if(dp[d][k-1] == 0) solve(d,k-1);
    k1 = dp[d][k-1];
    }

    dp[d][k] = (d1 + k1) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    solve(2500,0);

    int n; cin >> n;
    while(n--) {
        int t; cin >> t;
        if(t%2) cout << 0;
        else cout << dp[t/2][0];
        cout << '\n';
    }

    return 0;
=======
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
typedef long long ll;

ll dp[5001][5001];

//solve 에서 dp[d][k] 를 정의해준다.
void solve(int d,int k) {
    if(d == 0) {
        dp[d][k] = 1;
        return;
    }
    ll d1 = 0;
    ll k1 = 0;    

    if(dp[d-1][k+1] == 0) solve(d-1,k+1);

    d1 = dp[d-1][k+1];
    

    if(k>0) {
    if(dp[d][k-1] == 0) solve(d,k-1);
    k1 = dp[d][k-1];
    }

    dp[d][k] = (d1 + k1) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    solve(2500,0);

    int n; cin >> n;
    while(n--) {
        int t; cin >> t;
        if(t%2) cout << 0;
        else cout << dp[t/2][0];
        cout << '\n';
    }

    return 0;
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}