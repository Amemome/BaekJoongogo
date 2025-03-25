<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int resp;
    int ar,br;
    vector<int> a1(10000);
    vector<int> b1(10000);
    for(int i = 0; i < 10000; i++) {
        a1[i] = i+1;
        b1[i] = i+1;
    }

    random_device rd; 
    shuffle(a1.begin(),a1.end(),mt19937(rd()));
    shuffle(b1.begin(),b1.end(),mt19937(rd()));


    for(int a : a1) {
        cout << "? A " << a << endl;
        cin >> resp;
        ar = a;
        if(resp == 1) break;
    }
    resp = 0;   
    for(int b : b1) {
        cout << "? B " << b << endl;
        cin >> resp;
        br= b;
        if(resp == 1) break;
    }

    cout << "! "<<ar+br;
    
    return 0;
}
=======
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int resp;
    int ar,br;
    vector<int> a1(10000);
    vector<int> b1(10000);
    for(int i = 0; i < 10000; i++) {
        a1[i] = i+1;
        b1[i] = i+1;
    }

    random_device rd; 
    shuffle(a1.begin(),a1.end(),mt19937(rd()));
    shuffle(b1.begin(),b1.end(),mt19937(rd()));


    for(int a : a1) {
        cout << "? A " << a << endl;
        cin >> resp;
        ar = a;
        if(resp == 1) break;
    }
    resp = 0;   
    for(int b : b1) {
        cout << "? B " << b << endl;
        cin >> resp;
        br= b;
        if(resp == 1) break;
    }

    cout << "! "<<ar+br;
    
    return 0;
}
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
