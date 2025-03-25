#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int resp;
    int a;
    for(a= 1; a <= 9; a++) {
        cout << "? A " << a << endl;
        cin >> resp;

        if(resp == 1){
            int b;
            for(b = 1; b <= 9; b++) {
                cout << "? B " << b << endl;
                cin >> resp;
                if(resp == 1) break;
            }
            cout << "! " << a + b;
        }
    }

    
    return 0;
}
