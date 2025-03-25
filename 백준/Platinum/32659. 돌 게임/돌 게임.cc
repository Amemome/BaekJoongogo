<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
B.WBW
.BWBW

W.BWB
WB.WB
각각의 돌 사이의 거리를 개별의 게임으로 보기? -> 이게 가능한게 돌이 번갈아서 배치되어있음..
*/


int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    int check = 0;
    int dist = 0;
    ll result = 0;
    vector<int> arr;
    for(auto c : s) {
        if(c!='.') check++;
        if(check) dist++;
        if(check==2) {
            check=0;
            result ^= dist-2;
            dist=0;
        }
    }
    if(result) cout << "Win";
    else cout <<"Lose";
    


}



=======
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
B.WBW
.BWBW

W.BWB
WB.WB
각각의 돌 사이의 거리를 개별의 게임으로 보기? -> 이게 가능한게 돌이 번갈아서 배치되어있음..
*/


int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    int check = 0;
    int dist = 0;
    ll result = 0;
    vector<int> arr;
    for(auto c : s) {
        if(c!='.') check++;
        if(check) dist++;
        if(check==2) {
            check=0;
            result ^= dist-2;
            dist=0;
        }
    }
    if(result) cout << "Win";
    else cout <<"Lose";
    


}



>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
