<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
typedef long long ll;;

int n , w ; 

//min 이니 마지막에,,

void filldp(int start,int arr[2][10010],int dp[3][10010]) {
    for(int i = start; i < n; i++) {

        dp[0][i+1] = min({dp[1][i]+1,dp[2][i]+1,dp[0][i] + ((arr[0][i] + arr[1][i] <= w) ? 1 : 2)} );
        if(i > 0 && arr[0][i] + arr[0][i-1] <= w && arr[1][i] + arr[1][i-1] <= w) {
            dp[0][i+1] = min(dp[0][i+1],dp[0][i-1]+2);
        }
        dp[1][i+1] = dp[0][i+1]+1;
        if(arr[0][i] + arr[0][i+1] <= w) dp[1][i+1] = min(dp[1][i+1],dp[2][i]+1);

        dp[2][i+1] = dp[0][i+1]+1;
        if(arr[1][i] + arr[1][i+1] <= w) dp[2][i+1] = min(dp[2][i+1],dp[1][i]+1);
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) {

    cin >> n >> w;

    int arr[2][10010] = {};
    int dp[3][10010] = {};  

    int result = INT_MAX;

    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < n; i++) cin >> arr[j][i];
    }

    if(n==1) { //1일때 예외처리.
        if(arr[1][0] + arr[0][0] <= w) cout << 1;
        else cout << 2;
        cout << '\n';
        continue;
    }

    dp[1][0] = dp[2][0] = 1;
    filldp(0,arr,dp);

    result = min(result,dp[0][n]);

    if(arr[0][0] + arr[0][n-1] <= w) {
        dp[1][1] = 2;
        dp[0][1] = 1;
        dp[2][1] = (arr[1][0] + arr[1][1] <= w) ? 1: 2;
        filldp(1,arr,dp);
        result = min(result,dp[2][n-1]+1);
    }

    if(arr[1][0] + arr[1][n-1] <= w) {
        dp[2][1] = 2;
        dp[0][1] = 1;
        dp[1][1] = (arr[0][0] + arr[0][1] <= w) ? 1: 2;
        filldp(1,arr,dp);
        result = min(result,dp[1][n-1]+1);
    }

    if(arr[0][0] + arr[0][n-1] <= w && arr[1][0] + arr[1][n-1] <= w) {
        dp[0][1] = 0;
        dp[1][1] = 1;
        dp[2][1] = 1;
        filldp(1,arr,dp);
        result = min(result,dp[0][n-1]+2);
    }

    cout << result << '\n';
    }

    return 0;
=======
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
typedef long long ll;;

int n , w ; 

//min 이니 마지막에,,

void filldp(int start,int arr[2][10010],int dp[3][10010]) {
    for(int i = start; i < n; i++) {

        dp[0][i+1] = min({dp[1][i]+1,dp[2][i]+1,dp[0][i] + ((arr[0][i] + arr[1][i] <= w) ? 1 : 2)} );
        if(i > 0 && arr[0][i] + arr[0][i-1] <= w && arr[1][i] + arr[1][i-1] <= w) {
            dp[0][i+1] = min(dp[0][i+1],dp[0][i-1]+2);
        }
        dp[1][i+1] = dp[0][i+1]+1;
        if(arr[0][i] + arr[0][i+1] <= w) dp[1][i+1] = min(dp[1][i+1],dp[2][i]+1);

        dp[2][i+1] = dp[0][i+1]+1;
        if(arr[1][i] + arr[1][i+1] <= w) dp[2][i+1] = min(dp[2][i+1],dp[1][i]+1);
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) {

    cin >> n >> w;

    int arr[2][10010] = {};
    int dp[3][10010] = {};  

    int result = INT_MAX;

    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < n; i++) cin >> arr[j][i];
    }

    if(n==1) { //1일때 예외처리.
        if(arr[1][0] + arr[0][0] <= w) cout << 1;
        else cout << 2;
        cout << '\n';
        continue;
    }

    dp[1][0] = dp[2][0] = 1;
    filldp(0,arr,dp);

    result = min(result,dp[0][n]);

    if(arr[0][0] + arr[0][n-1] <= w) {
        dp[1][1] = 2;
        dp[0][1] = 1;
        dp[2][1] = (arr[1][0] + arr[1][1] <= w) ? 1: 2;
        filldp(1,arr,dp);
        result = min(result,dp[2][n-1]+1);
    }

    if(arr[1][0] + arr[1][n-1] <= w) {
        dp[2][1] = 2;
        dp[0][1] = 1;
        dp[1][1] = (arr[0][0] + arr[0][1] <= w) ? 1: 2;
        filldp(1,arr,dp);
        result = min(result,dp[1][n-1]+1);
    }

    if(arr[0][0] + arr[0][n-1] <= w && arr[1][0] + arr[1][n-1] <= w) {
        dp[0][1] = 0;
        dp[1][1] = 1;
        dp[2][1] = 1;
        filldp(1,arr,dp);
        result = min(result,dp[0][n-1]+2);
    }

    cout << result << '\n';
    }

    return 0;
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}