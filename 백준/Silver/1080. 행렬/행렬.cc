<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int matrix[101][101];
int goal[101][101];
int cnt = 0;

void change(int y,int x) {
    cnt++;
    for(int i = y; i < y+3; i++) {
        for(int j = x; j < x+3; j++) {
            matrix[i][j] ^= 1;
        }
    }
}
/*
어차피 뒤집는 연산이니 뭘 먼저하든 상관이 없을 것. 그리고 2번 연산하는 것은 0번연산하는거랑 같음
50 x 50 이니까 2500 번 ? 가능.순차적으로 보자.

0 -> 1
1 -> 0

*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m ; cin >> n >> m;
    string s;
    for(int y = 0; y < n; y++) {
        cin >> s;
        for(int x = 0; x < m; x++) {
            matrix[y][x] = s[x] - '0';
        }
    }
    for(int y = 0; y < n; y++) {
        cin >> s;
        for(int x = 0; x < m; x++) {
            goal[y][x] = s[x] - '0';
        }
    }    

    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            matrix[y][x] = (matrix[y][x] ^ goal[y][x]); //xor한 값으로 변신.
        }
    }    
    

    // for(int y = 0; y < n; y++) {
    //     for(int x = 0; x < m; x++) {
    //         cout << matrix[y][x];
    //     }
    //     cout << endl;
    // }   




    for(int y = 0; y < n-2; y++) {
        for(int x = 0; x < m-2; x++) {
            if(matrix[y][x] == 1) change(y,x);
        }
    }   

    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            if(matrix[y][x] == 1) {
                cout << -1;
                return 0;
            }
        }
    }    



    cout << cnt;
    
    
=======
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int matrix[101][101];
int goal[101][101];
int cnt = 0;

void change(int y,int x) {
    cnt++;
    for(int i = y; i < y+3; i++) {
        for(int j = x; j < x+3; j++) {
            matrix[i][j] ^= 1;
        }
    }
}
/*
어차피 뒤집는 연산이니 뭘 먼저하든 상관이 없을 것. 그리고 2번 연산하는 것은 0번연산하는거랑 같음
50 x 50 이니까 2500 번 ? 가능.순차적으로 보자.

0 -> 1
1 -> 0

*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m ; cin >> n >> m;
    string s;
    for(int y = 0; y < n; y++) {
        cin >> s;
        for(int x = 0; x < m; x++) {
            matrix[y][x] = s[x] - '0';
        }
    }
    for(int y = 0; y < n; y++) {
        cin >> s;
        for(int x = 0; x < m; x++) {
            goal[y][x] = s[x] - '0';
        }
    }    

    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            matrix[y][x] = (matrix[y][x] ^ goal[y][x]); //xor한 값으로 변신.
        }
    }    
    

    // for(int y = 0; y < n; y++) {
    //     for(int x = 0; x < m; x++) {
    //         cout << matrix[y][x];
    //     }
    //     cout << endl;
    // }   




    for(int y = 0; y < n-2; y++) {
        for(int x = 0; x < m-2; x++) {
            if(matrix[y][x] == 1) change(y,x);
        }
    }   

    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            if(matrix[y][x] == 1) {
                cout << -1;
                return 0;
            }
        }
    }    



    cout << cnt;
    
    
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}