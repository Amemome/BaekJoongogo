#include <bits/stdc++.h>

using namespace std;

/*
타일링 문제 처럼 구간구간을 계속 최소화 해 나가면 되는 문제,, 근데 이걸 어케함.
*/


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int house[3][1001] = {};
    int mim = INT_MAX;

    for(int i = 0; i < n; i++) {
        int r,g,b; cin >> house[0][i] >> house[1][i] >> house[2][i];
    }


    { //0
    int dp[3][1001] = {};
    dp[0][0] = house[0][0];
    dp[1][0] = dp[2][0] = 10000000;
    for(int i = 1; i < n; i++) {
        dp[0][i] = min(dp[1][i-1],dp[2][i-1]) + house[0][i];
        dp[1][i] = min(dp[0][i-1],dp[2][i-1]) + house[1][i];
        dp[2][i] = min(dp[1][i-1],dp[0][i-1]) + house[2][i];
    }
    
    if(mim > min(dp[1][n-1] , dp[2][n-1])) mim = min(dp[1][n-1] , dp[2][n-1]);

    }

    { // 1
    int dp[3][1001] = {};
    dp[1][0] = house[1][0];
    dp[0][0] = dp[2][0] = 10000000;
    for(int i = 1; i < n; i++) {
        dp[0][i] = min(dp[1][i-1],dp[2][i-1]) + house[0][i];
        dp[1][i] = min(dp[0][i-1],dp[2][i-1]) + house[1][i];
        dp[2][i] = min(dp[1][i-1],dp[0][i-1]) + house[2][i];
    }
    
    if(mim > min(dp[0][n-1] , dp[2][n-1])) mim = min(dp[0][n-1] , dp[2][n-1]);
    }

    {
    int dp[3][1001] = {};
    dp[2][0] = house[2][0];
    dp[1][0] = dp[0][0] = 10000000;
    for(int i = 1; i < n; i++) {
        dp[0][i] = min(dp[1][i-1],dp[2][i-1]) + house[0][i];
        dp[1][i] = min(dp[0][i-1],dp[2][i-1]) + house[1][i];
        dp[2][i] = min(dp[1][i-1],dp[0][i-1]) + house[2][i];
    }
    

    if(mim > min(dp[0][n-1] , dp[1][n-1])) mim = min(dp[0][n-1] , dp[1][n-1]);

    }

    cout << mim;

    return 0;
}