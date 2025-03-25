    #include <bits/stdc++.h>

    using namespace std;

    int dp[1002][10000];

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n,t,m;
        cin >> n >> t >> m;

        for(int x = 0; x < 1002; x++) {
            for(int y = 0; y < 10000; y++) {
                dp[x][y] = INT_MAX-10000000;
            }
        }
        
        int s,e;
        cin >> s >> e;

        dp[0][s] = 0;
        
        for(int i = 0; i < t; i++) {
            for(int N = 0; N < n; N++) {
                dp[i+1][N] = dp[i][N];
            }
            for(int zz = 0; zz < m; zz++) {
                int a,b,w;
                cin >> a >> b >> w;

                dp[i+1][b] = min(dp[i+1][b],dp[i][a] +  w);
                dp[i+1][a] = min(dp[i+1][a],dp[i][b] +  w);
            }
        }
        
        int result = INT_MAX-10000000;
        for(int i = 0; i <= t; i++) {
            result = min(result,dp[i][e]);
        
            
        }

        if(result == INT_MAX-10000000) cout << -1;
        else {
            cout << result;
        }
        
    }