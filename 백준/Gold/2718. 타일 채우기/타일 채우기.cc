<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007

/*
 제한 작으니까 그냥 ㄱㄱ
*/

long long dp[100001];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int mxm = 0;
    vector<int> arr;
    while(n--) {
        int d; cin >> d;
        mxm = max(mxm,d);
        arr.push_back(d);
    }

    n = mxm;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;
    

    for(int i = 3; i <= n; i++) {

        long long sum = 0;
        for(int x = i; x > 2; x--) {
            sum += dp[i-x]*(2+!(x%2));
        }
        dp[i] = (dp[i-1] + dp[i-2]*4 + sum);
    }

    for(auto x : arr) cout << dp[x] << '\n';
    return 0;
=======
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007

/*
 제한 작으니까 그냥 ㄱㄱ
*/

long long dp[100001];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int mxm = 0;
    vector<int> arr;
    while(n--) {
        int d; cin >> d;
        mxm = max(mxm,d);
        arr.push_back(d);
    }

    n = mxm;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;
    

    for(int i = 3; i <= n; i++) {

        long long sum = 0;
        for(int x = i; x > 2; x--) {
            sum += dp[i-x]*(2+!(x%2));
        }
        dp[i] = (dp[i-1] + dp[i-2]*4 + sum);
    }

    for(auto x : arr) cout << dp[x] << '\n';
    return 0;
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}