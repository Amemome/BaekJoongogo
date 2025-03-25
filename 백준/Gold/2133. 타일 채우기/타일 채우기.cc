#include <bits/stdc++.h>

using namespace std;

/*
짝수를 뭉텅이로 봐야되나?
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    if(n%2) {
        cout << 0;
        return 0;
    }

    long long dp[31] = {0,0,3};

    for(int i = 4; i < 31; i+=2) {
        dp[i] += 3*dp[i-2] + 2;
        for(int d = i - 4; d > 0; d-=2) {
            dp[i] += 2 * dp[d];
        }
    }
    cout << dp[n];



    

    return 0;
}