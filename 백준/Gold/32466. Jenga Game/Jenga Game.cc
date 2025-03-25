<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*

*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin>>tt;
    while(tt--) {
        int n; cin >> n;
        n--;

        string s; cin >> s;
        int res = 0;
        while(n--) {
            cin >> s;
            if(s == "111") {
                res ^= 2;
            } else 
            if(s == "110" || s == "011") {
                res ^= 1;
            }
        }
        if(res != 0) cout << "Yesyes" << '\n';
        else cout << "Nono" << '\n';
    }
=======
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*

*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin>>tt;
    while(tt--) {
        int n; cin >> n;
        n--;

        string s; cin >> s;
        int res = 0;
        while(n--) {
            cin >> s;
            if(s == "111") {
                res ^= 2;
            } else 
            if(s == "110" || s == "011") {
                res ^= 1;
            }
        }
        if(res != 0) cout << "Yesyes" << '\n';
        else cout << "Nono" << '\n';
    }
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}