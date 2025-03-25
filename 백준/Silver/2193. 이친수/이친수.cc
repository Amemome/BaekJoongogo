<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

   
/*
1 000

1 -> 1
2 -> 10
3 -> 101, 100
4 -> 1000 1010 1001
5 -> 10000 , 10101 10100 , 10010, 10001
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    ll dp[100] = {};
    ll sdp[100] = {};
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    sdp[1] = 1;
    sdp[2] = 2;
    sdp[3] = 4;
    for(int i = 4; i < 91; i++) {
        dp[i] = 1 + sdp[i-2];
        sdp[i] = sdp[i-1] + dp[i];
    }
    
    cout <<  dp[n];
=======
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

   
/*
1 000

1 -> 1
2 -> 10
3 -> 101, 100
4 -> 1000 1010 1001
5 -> 10000 , 10101 10100 , 10010, 10001
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    ll dp[100] = {};
    ll sdp[100] = {};
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    sdp[1] = 1;
    sdp[2] = 2;
    sdp[3] = 4;
    for(int i = 4; i < 91; i++) {
        dp[i] = 1 + sdp[i-2];
        sdp[i] = sdp[i-1] + dp[i];
    }
    
    cout <<  dp[n];
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}