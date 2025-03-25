#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
님게임에서 내 상태의 그런디수가 0이 아니면, 무조건 0으로 만들 수 있음. 이 말은 상대가 뭘 하던 0으로 만들 수 있다 이거임.
마지막에 가져간 사람이 지는거니, 1인 돌 무더기를 제외하고 나머지를 그런디수 처리하면 되는거 아닌가?
1인돌 무더기가 없을때는 어떻게 하는가 ? 님게임 어차피 돌리다 보면, 결국 0으로 만들 수 있을텐데, 마지막에 어케어케 잘 하면 1 되지 않을까요

1이 하나라도 있으면 됨.
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    bool isOne = true;

    vector<ll> dol(n+1);
    for(int i = 0; i < n; i++) cin >> dol[i];
    ll result = 0;

    for(int i = 0; i < n; i++) {
        if(dol[i] != 1) isOne = false;
        result = (result^(ll)dol[i]);
    }   
    result ^= isOne;

    if(result != 0) {
        cout << "koosaga";
    } else {
        cout << "cubelover";
    }
}