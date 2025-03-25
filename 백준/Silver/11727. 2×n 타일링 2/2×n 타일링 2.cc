<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

/*

*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int dp[1001] = {0,1,3};
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + 2*dp[i-2])%10007;
    }
    cout << dp[n];


    

    return 0;
=======
#include <bits/stdc++.h>

using namespace std;

/*

*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int dp[1001] = {0,1,3};
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + 2*dp[i-2])%10007;
    }
    cout << dp[n];


    

    return 0;
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}