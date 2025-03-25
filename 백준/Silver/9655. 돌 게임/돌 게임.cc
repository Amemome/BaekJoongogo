<<<<<<< HEAD
#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

/*
내가 최대로 먹기 그리고 상대 먹는걸 방해하기. 이 두개를 한번에 하려면 어떻게 해야할까?
일단 내가 최대로 먹을 수 있는 것은 먹는게 맞음. 아니 맞나?

*/
struct pos{
    int x,y;
    pos(int x,int y) : x(x) , y(y) {}
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    
    vector<bool> dp(1001);

    dp[n] = true;

    for(int i = n; i > 0; i--) {
        if(i-3 >= 0) dp[i-3] = !dp[i];
        if(i-1 >= 0) dp[i-1] = !dp[i];
    } 


    if(dp[0]) cout << "CY";
    else cout << "SK";
    

    return 0;
=======
#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

/*
내가 최대로 먹기 그리고 상대 먹는걸 방해하기. 이 두개를 한번에 하려면 어떻게 해야할까?
일단 내가 최대로 먹을 수 있는 것은 먹는게 맞음. 아니 맞나?

*/
struct pos{
    int x,y;
    pos(int x,int y) : x(x) , y(y) {}
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    
    vector<bool> dp(1001);

    dp[n] = true;

    for(int i = n; i > 0; i--) {
        if(i-3 >= 0) dp[i-3] = !dp[i];
        if(i-1 >= 0) dp[i-1] = !dp[i];
    } 


    if(dp[0]) cout << "CY";
    else cout << "SK";
    

    return 0;
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}