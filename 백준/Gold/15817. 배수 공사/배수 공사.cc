<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
long long dp[10001];

/*
0을 1이라 둔다 1이상인 것에 대해서 값을 더하는거지.
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

	dp[0] = 1;

    for(int i = 0; i < n; i++) {
        int l,c; cin >> l >> c;
        for(int b = k; b >= 0; b--) {
            if(dp[b]) {
				for(int j = 1; j <= c; j++) {
					if(b+l*j >k) break;
					dp[b+l*j] +=  dp[b];
				}
			}
		}	
	}

    cout << dp[k];




    
    
    return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
long long dp[10001];

/*
0을 1이라 둔다 1이상인 것에 대해서 값을 더하는거지.
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

	dp[0] = 1;

    for(int i = 0; i < n; i++) {
        int l,c; cin >> l >> c;
        for(int b = k; b >= 0; b--) {
            if(dp[b]) {
				for(int j = 1; j <= c; j++) {
					if(b+l*j >k) break;
					dp[b+l*j] +=  dp[b];
				}
			}
		}	
	}

    cout << dp[k];




    
    
    return 0;
}
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
