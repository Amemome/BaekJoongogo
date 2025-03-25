<<<<<<< HEAD
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

/*
1 2 5 로 보자.

1
1 1 / 2
1 1 1 / 2 1
1 1 1 1 / 2 2/ 2 1 1
1 1 1 1 1/ 2 1 1 1 / 2 2 1 / 5
1 1 1 1 1 1/ 2 1 1 1 1/ 2 2 1 1/ 2 2 2 / 5 1
1 1 1 1 1 1 1 / 2 1 1 1 1 1 / 2 2 1 1 1 / 2 2 2 1/ 5 1 1/ 5 2 
1 1 1 1 1 1 1 1 / 2 1 1 1 1 1 1 / 2 2 1 1 1 1 / 2 2 2 1 1 / 2 2 2 2 / 5 1 1 1 / 5 2 1
1 1 1 1 1 1 1 1 1 / 2 1 1 1 1 1 1 1 / 2 2 1 1 1 1 1 / 2 2 2 1 1 1 / 2 2 2 2 1 / 5 1 1 1 1 / 5 2 1 1 / 5 2 2
1 1 1 1 1 1 1 1 1 1 / 2 1 1 1 1 1 1 1 1 / 2 2 1 1 1 1 1 1 / 2 2 2 1 1 1 1 / 2 2 2 2 1 1 / 2 2 2 2 2 / 5 1 1 1 1 1 / 5 2 1 1 1 / 5 2 2 1 / 5 5
아 동전문젠데 경우의수 출력이구나
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n,k;
    cin >> n >> k;

    long long dp[10001] = {0}; //이전에 선택한 동전의 

    int coin[101] = {0};

    for(int i = 0;i < n; i++) { //코인배열에도 넣고 dp에서 각 코인을 1로 만들어줌.
        int c; cin >> c;
        coin[i] = c;
    }
    dp[0] = 1;


    for(int x = 0; x < n; x++) {
        int c = coin[x];
        for(int i = 1; i <= k; i++) {
            if(i-c < 0) continue;
            dp[i] = dp[i] + dp[i-c];
        }
    }

    cout << dp[k];
    
    return 0;
=======
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

/*
1 2 5 로 보자.

1
1 1 / 2
1 1 1 / 2 1
1 1 1 1 / 2 2/ 2 1 1
1 1 1 1 1/ 2 1 1 1 / 2 2 1 / 5
1 1 1 1 1 1/ 2 1 1 1 1/ 2 2 1 1/ 2 2 2 / 5 1
1 1 1 1 1 1 1 / 2 1 1 1 1 1 / 2 2 1 1 1 / 2 2 2 1/ 5 1 1/ 5 2 
1 1 1 1 1 1 1 1 / 2 1 1 1 1 1 1 / 2 2 1 1 1 1 / 2 2 2 1 1 / 2 2 2 2 / 5 1 1 1 / 5 2 1
1 1 1 1 1 1 1 1 1 / 2 1 1 1 1 1 1 1 / 2 2 1 1 1 1 1 / 2 2 2 1 1 1 / 2 2 2 2 1 / 5 1 1 1 1 / 5 2 1 1 / 5 2 2
1 1 1 1 1 1 1 1 1 1 / 2 1 1 1 1 1 1 1 1 / 2 2 1 1 1 1 1 1 / 2 2 2 1 1 1 1 / 2 2 2 2 1 1 / 2 2 2 2 2 / 5 1 1 1 1 1 / 5 2 1 1 1 / 5 2 2 1 / 5 5
아 동전문젠데 경우의수 출력이구나
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n,k;
    cin >> n >> k;

    long long dp[10001] = {0}; //이전에 선택한 동전의 

    int coin[101] = {0};

    for(int i = 0;i < n; i++) { //코인배열에도 넣고 dp에서 각 코인을 1로 만들어줌.
        int c; cin >> c;
        coin[i] = c;
    }
    dp[0] = 1;


    for(int x = 0; x < n; x++) {
        int c = coin[x];
        for(int i = 1; i <= k; i++) {
            if(i-c < 0) continue;
            dp[i] = dp[i] + dp[i-c];
        }
    }

    cout << dp[k];
    
    return 0;
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}