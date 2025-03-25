#include <bits/stdc++.h>

using namespace std;

/*
대충 타일 넣고, 1은 그냥 안ㅇ넣어도 알아서 들어가는 것으로
*/
long long dp[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> dp(n+1);
    vector<int> t;
    vector<int> p;
    int N = n;
    while(N--) {
        int a,b;
        cin >> a >> b;
        t.push_back(a);
        p.push_back(b);
    }

    for(int i = 0; i < n; i++) { // 0 ~ n-1 까지
        dp[i+1] = max(dp[i+1],dp[i]);
        int ti = t[i];
        int pi = p[i];
        if(i+ti > n) continue; 
        dp[i+ti] = max(dp[i+ti],dp[i]+pi);
    }
    
    cout << dp[n];
    return 0;
}