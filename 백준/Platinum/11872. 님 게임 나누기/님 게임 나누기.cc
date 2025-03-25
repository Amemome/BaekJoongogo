<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    long long result = 0;
    while(t--){
        int k; cin >> k;
        if(k%4 == 3) k++;
        else if(k%4==0)k--;
        result ^= k;
    }
    if(result != 0) cout << "koosaga";
    else cout << "cubelover";
=======
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    long long result = 0;
    while(t--){
        int k; cin >> k;
        if(k%4 == 3) k++;
        else if(k%4==0)k--;
        result ^= k;
    }
    if(result != 0) cout << "koosaga";
    else cout << "cubelover";
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}