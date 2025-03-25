<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll floorsum(ll a, ll b,ll c,ll n){
  if(!a) return (b / c) * (n + 1);
  if(a >= c or b >= c) return ( ( n * (n + 1) ) / 2) * (a / c) + (n + 1) * (b / c) + floorsum(a % c, b % c, c, n);
  long long m = (a * n + b) / c;
  return m * n - floorsum(c, c - b - 1, a, m - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    
    while(tt--) { 
        ll p,q,n; cin >> p >> q >> n;
        ll result = p*n*(n+1)/2;
        result -= q * floorsum(p,0,q,n);
        cout << result << '\n';
    }

}

=======
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll floorsum(ll a, ll b,ll c,ll n){
  if(!a) return (b / c) * (n + 1);
  if(a >= c or b >= c) return ( ( n * (n + 1) ) / 2) * (a / c) + (n + 1) * (b / c) + floorsum(a % c, b % c, c, n);
  long long m = (a * n + b) / c;
  return m * n - floorsum(c, c - b - 1, a, m - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    
    while(tt--) { 
        ll p,q,n; cin >> p >> q >> n;
        ll result = p*n*(n+1)/2;
        result -= q * floorsum(p,0,q,n);
        cout << result << '\n';
    }

}

>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
