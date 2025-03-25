#include <bits/stdc++.h>

using namespace std;
typedef long long ll;;

#define SZ 1000010

vector<int> prime;
int mu[SZ+1],sp[SZ+1];
void sieve() {
    mu[1] = 1;
    for(int i=2; i<=SZ; i++) {
        if(!sp[i]){
            prime.push_back(i);
            sp[i] = i;
            mu[i] = -1;
        }
        for(auto p:prime){
            if(p>sp[i] || i*p > SZ) break;
            sp[i*p] = p;
            if(i%p==0) {
                mu[i*p] = 0;
                break;
            }  else {
                mu[i*p] = -mu[i];
            }
        }
    }
    for(int i = 1; i < SZ; i++) mu[i] += mu[i-1];
}

unordered_map<ll,ll> Cache;

ll Mer(ll n) {
    if(n<SZ) return mu[n];
    if (Cache.count(n)) return Cache[n];
    ll result = 1; ll j;
    for(ll i = 2; i <= n; i = j + 1) {
        ll j = n/(n/i);
        result -= (j-i+1)*Mer(n/i);
    }
    Cache[n] = result;
    return result;
}

ll solve(long long k) {
    ll result = 0; ll j;
    for(ll i = 1; i * i <= k; i=j+1) {
        j = k/(k/i);
        result += (Mer(j)-Mer(i-1))*((k/i)/i);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();



    long long r; cin >> r;
    long long lo = -1, hi = 2000000000;
        
    while(lo + 1 < hi) {
        long long mid =(lo+hi)/ 2;
        if(solve(mid) < r) lo = mid;
        else hi = mid; 
    }

    cout << hi;
    

    return 0;
}