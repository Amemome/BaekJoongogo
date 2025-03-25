<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000003




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++) {
        int x,y; cin >> x >> y;
        a[i] = {x,y};
    }
    int idx = 1;
    int left = 0, right = 0;
    left = a[0].first;
    right = a[0].second;
    ll result = 0;

    while(idx < n) {
        int x,y;
        tie(x,y) = a[idx];
        if(left <= x && x  <= right) {
            if(left <= y && y <= right) {
            } else {
                right = y;
            }
        } else {
            result += right - left;
            left = x;
            right = y;
        }
        idx++;
    }
    result += right - left;

    cout << result;
    

=======
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000003




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++) {
        int x,y; cin >> x >> y;
        a[i] = {x,y};
    }
    int idx = 1;
    int left = 0, right = 0;
    left = a[0].first;
    right = a[0].second;
    ll result = 0;

    while(idx < n) {
        int x,y;
        tie(x,y) = a[idx];
        if(left <= x && x  <= right) {
            if(left <= y && y <= right) {
            } else {
                right = y;
            }
        } else {
            result += right - left;
            left = x;
            right = y;
        }
        idx++;
    }
    result += right - left;

    cout << result;
    

>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}