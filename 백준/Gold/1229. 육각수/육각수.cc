#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    vector<int> hex(709);
    vector<int> sum(1000010,6);
    sum[0] = 0;
    hex[0] = 1;
    for(int i = 0; i < 1000; i++) {
        hex[i+1] = hex[i] + 5 + 4 * i;
        if(hex[i+1] > 1000000) break;
    }
    for(int i = 1; i <= N; i++) {
        for(auto x : hex) {
            if(x>i) break;
            sum[i] = min(sum[i],sum[i-x]+1);
        }
    }

    cout << sum[N];

}