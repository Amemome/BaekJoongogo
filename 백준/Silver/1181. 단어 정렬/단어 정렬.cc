#include <bits/stdc++.h>

using namespace std;

bool compare(const string & a, const string & b) {
    if(a.length() == b.length()) {
        return a<b;
    } else {
        return a.length() < b.length();
    }
}

struct Cmp {
    bool operator()(const string & a, const string & b) const {
        if(a.length() == b.length()) {
            return a<b;
        } else {
            return a.length() < b.length();
        }
    }
};


long long dp[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    set<string,Cmp> dic;
    while(n--) {
        string s; cin >> s;
        dic.insert(s);
    }
    // sort(dic.begin(),dic.end(),compare);

    for(auto x : dic) cout << x << '\n';
    return 0;
}
