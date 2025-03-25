<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        pq.push(k);
    }
    int result = 0;
    while(pq.size()>1) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        result += x + y;
        pq.push(x+y);
    }
    
    cout << result;

=======
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        pq.push(k);
    }
    int result = 0;
    while(pq.size()>1) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        result += x + y;
        pq.push(x+y);
    }
    
    cout << result;

>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}