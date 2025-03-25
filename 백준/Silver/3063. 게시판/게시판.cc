<<<<<<< HEAD
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

/*
LCS .. 해놓고도 까먹은.. ... 가장 떠오르는 캐이스가
1 5 1 2 3 6 8

(5,2) 달아놓음.
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int xL1 , yL1 , xH1 , yH1, xL2, yL2 ,xH2, yH2;
        cin >>  xL1 >> yL1 >> xH1 >> yH1>> xL2>> yL2 >>xH2>> yH2;
        if(xL1 >= xH2 || yL1 >= yH2 || xL2 >= xH1 || yL2 >= yH1) {
            cout << (xH1 - xL1) * (yH1-yL1) << '\n';
            continue;
        }
        int xL,xH,yL,yH;
        xL = max(xL1,xL2);
        xH = min(xH1,xH2);
        yL = max(yL1,yL2);
        yH = min(yH1,yH2);

        cout <<((xH1 - xL1) * (yH1-yL1)) - ((xH-xL) * (yH-yL)) << '\n';

    }
    
    return 0;
=======
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

/*
LCS .. 해놓고도 까먹은.. ... 가장 떠오르는 캐이스가
1 5 1 2 3 6 8

(5,2) 달아놓음.
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int xL1 , yL1 , xH1 , yH1, xL2, yL2 ,xH2, yH2;
        cin >>  xL1 >> yL1 >> xH1 >> yH1>> xL2>> yL2 >>xH2>> yH2;
        if(xL1 >= xH2 || yL1 >= yH2 || xL2 >= xH1 || yL2 >= yH1) {
            cout << (xH1 - xL1) * (yH1-yL1) << '\n';
            continue;
        }
        int xL,xH,yL,yH;
        xL = max(xL1,xL2);
        xH = min(xH1,xH2);
        yL = max(yL1,yL2);
        yH = min(yH1,yH2);

        cout <<((xH1 - xL1) * (yH1-yL1)) - ((xH-xL) * (yH-yL)) << '\n';

    }
    
    return 0;
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}