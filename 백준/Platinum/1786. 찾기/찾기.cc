#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

vector<int> w;

vector<int> failure(string & s) {
    vector<int> f(s.size());
    int j = 0;
    for(int i = 1; i < s.size(); i++) {
        while(j>0 && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = ++j;
    } return f;
}
ll kmp(string s, string p) {
    vector<int> f = failure(p);
    ll cnt = 0;
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        while(j>0 && s[i] != p[j]) j = f[j-1];
        if(s[i] == p[j]) j++;
        if(j == p.size()) {
            cnt++;
            w.emplace_back(i-j + 2);
        }
    } return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    string s,p;
    getline(cin,s);
    getline(cin,p);
    cout << kmp(s,p) << endl;
    for(auto x : w) cout << x << ' ';

    

    
    return 0;
}
