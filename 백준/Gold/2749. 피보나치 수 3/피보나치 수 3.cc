<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
typedef long long ll;

ll dp[1500015] = {0,1,1};

// 10 ^ 6 이니가 15 * 10 ^ 5 네요

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n; cin >> n;
    for(int i = 2; i < 1500015; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000;
    }

    n = n % 1500000;

    cout << dp[n];

    return 0;
=======
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
typedef long long ll;

ll dp[1500015] = {0,1,1};

// 10 ^ 6 이니가 15 * 10 ^ 5 네요

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n; cin >> n;
    for(int i = 2; i < 1500015; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000;
    }

    n = n % 1500000;

    cout << dp[n];

    return 0;
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}