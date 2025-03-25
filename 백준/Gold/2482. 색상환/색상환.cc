<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000003
vector<vector<ll>> com(1001,vector<ll>(1001)); // n 번째에 k색을 선택.방법수.

/*
중복 조합으로 해결가능. n 개의 칸막이에 n-k-k 개의 공을 집어넣는 방법의 수를 구하는거임.

중복조합.   n+r-1 C r 임.

r 은, n-k-k-1 이고  은 k 임.
그리고 다른건
n-k-k 이고     k-1 임.

그러면 
n-k-k-1 +k - 1 C 

01010
1010
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k; cin >> n >> k;

    for(int i = 1; i < 1001; i++) {
        com[i][i] = 1;
        com[i][1] = i;
        com[i][0] = 1;
    } 
    
    for(int i = 2; i < n; i++) {
        for(int j = 2; j < i; j++) {
            com[i][j] = (com[i-1][j] + com[i-1][j-1]) % MOD;
        }
    }
    if(2 * k > n) { //k의 두배가 더 크면 안됨.
        cout << 0;
        return 0;
    } else if(2 * k == n) {
        cout << 2;
        return 0;
    } else if(k==1) {
        cout << n;
        return 0;
    }
    ll result = 0; 
    result = (result + com[n-k-k-1 +k][n-k-k-1]) % MOD;
    result = (result + 2 * com[n-k-k +k-1][n-k-k]) % MOD; 

    cout << result%MOD;
}


// 칸막이가 k 개잖아. 공은 n - 2k - 1 개.
// n - 2k - 1 + k C n - 2k - 1 하면되는거아님?
=======
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000003
vector<vector<ll>> com(1001,vector<ll>(1001)); // n 번째에 k색을 선택.방법수.

/*
중복 조합으로 해결가능. n 개의 칸막이에 n-k-k 개의 공을 집어넣는 방법의 수를 구하는거임.

중복조합.   n+r-1 C r 임.

r 은, n-k-k-1 이고  은 k 임.
그리고 다른건
n-k-k 이고     k-1 임.

그러면 
n-k-k-1 +k - 1 C 

01010
1010
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k; cin >> n >> k;

    for(int i = 1; i < 1001; i++) {
        com[i][i] = 1;
        com[i][1] = i;
        com[i][0] = 1;
    } 
    
    for(int i = 2; i < n; i++) {
        for(int j = 2; j < i; j++) {
            com[i][j] = (com[i-1][j] + com[i-1][j-1]) % MOD;
        }
    }
    if(2 * k > n) { //k의 두배가 더 크면 안됨.
        cout << 0;
        return 0;
    } else if(2 * k == n) {
        cout << 2;
        return 0;
    } else if(k==1) {
        cout << n;
        return 0;
    }
    ll result = 0; 
    result = (result + com[n-k-k-1 +k][n-k-k-1]) % MOD;
    result = (result + 2 * com[n-k-k +k-1][n-k-k]) % MOD; 

    cout << result%MOD;
}


// 칸막이가 k 개잖아. 공은 n - 2k - 1 개.
// n - 2k - 1 + k C n - 2k - 1 하면되는거아님?
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
// 5 - 2  - 1  C 1