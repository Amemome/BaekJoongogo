<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*

A 부터 1 까지의 XOR 값을 구합시다. 그런데 이제 비트마다 보는.


111000000
111000001
111000010
111000011

*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b; cin >> a >> b;
    a = a-1;
    switch(a%4) {
        case 0:
            a = a;
            break;
        case 1:
            a = 1;
            break;
        case 2:
            a = a+1;
            break;
        case 3:
            a = 0;
            break;
    }

    switch(b%4) {
        case 0:
            b = b;
            break;
        case 1:
            b = 1;
            break;
        case 2:
            b = b+1;
            break;
        case 3:
            b = 0;
            break;
    }

    cout << (a ^ b);
    

}
=======
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*

A 부터 1 까지의 XOR 값을 구합시다. 그런데 이제 비트마다 보는.


111000000
111000001
111000010
111000011

*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b; cin >> a >> b;
    a = a-1;
    switch(a%4) {
        case 0:
            a = a;
            break;
        case 1:
            a = 1;
            break;
        case 2:
            a = a+1;
            break;
        case 3:
            a = 0;
            break;
    }

    switch(b%4) {
        case 0:
            b = b;
            break;
        case 1:
            b = 1;
            break;
        case 2:
            b = b+1;
            break;
        case 3:
            b = 0;
            break;
    }

    cout << (a ^ b);
    

}
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
