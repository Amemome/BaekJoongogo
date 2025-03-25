#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int phi[1001];

int POW(int a, int b, int MMM) { int ret = 1; for (; b; b >>= 1, a = (a * a) % MMM)if (b & 1)ret = (ret * a) % MMM; return ret; }


/*
Xb = Xb-1^Xb-1 으로 정의될 수 있다.
1 ~ 1001 까지 있을 때, phi(phi(phi(C))) 이런식으로 쌓이는건 최대 11번임.
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 1001;i++) phi[i] = i;
    for(int i = 2; i < 1001;i++) {
        if(phi[i] == i) {
            for(int j = i; j < 1001;j+=i) {
                phi[j] = phi[j] * (i-1) / i;
            }
        }
    }

    int t; cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        vector<int> modc; //index번 피함수가 적용됨. index range : 0~14
        int a,b,c; cin >> a >> b >> c;
        if(b==1) {
            cout << "Case #"<<tt<<": "<< POW(a,a,c)<< '\n'; 
            continue;
        }
        modc.push_back(c); 
        for(int i = c; i != 1; i = phi[i]) modc.push_back(phi[i]);

        vector<vector<int>> pb(modc.size(),vector<int>(1010));

        for(int i = 0; i < modc.size();i++) {
            pb[i][0] = POW(a,a,modc[i]); 
        }
        for(int i = 1; i < b; i++) {
            for(int j = 0; j < modc.size()-1; j++) {
                int exp = pb[j+1][i-1];
                int mod = modc[j+1];
                if(exp == 0) exp += modc[j+1];
                if(exp >= mod) exp = exp % mod + mod;
                pb[j][i] = POW(pb[j][i-1],exp,modc[j]);
            }
        }

        // for(int i = 0; i < b; i++) {
        //     for(int j = 0; j < modc.size()-1; j++) {
        //         cout << pb[j][i] << ' ';
        //     }
        //     cout << endl;
        // }

        cout << "Case #"<<tt<<": "<< pb[0][b-1]<< '\n';
    }

    


    
}