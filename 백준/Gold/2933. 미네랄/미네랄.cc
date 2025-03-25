<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int r,c; 
int ddx[4] = {1,0,-1,0};
int ddy[4] = {0,-1,0,1};
char board[101][101];


void remove(int row,int dir) {
    row = r - row;
    if(!dir) {
        for(int i = 0; i < c; i++) {
            if(board[row][i] == 'x') {
                board[row][i] = '.';
                return;
            }
        }
    } else {
        for(int i = c-1; i >= 0; i--) {
            if(board[row][i] == 'x') {
                board[row][i] = '.';
                return;
            }
        }
    }
}

int cluster(map<int,set<int,greater<int>>> & S) {
    int cnt = 0;
    int visit[101][101] = {0};

    for(int y = 0; y < c; y++) { //땅바닥 붙어있는 놈들 방문처리.
        int x = r-1;
        if(visit[x][y] == false && board[x][y] == 'x') {
            queue<pair<int,int>> Q;
            Q.push({x,y});
            visit[x][y] = true;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int dx = cur.first + ddx[dir];
                    int dy = cur.second + ddy[dir];
                    if(dx<0 || dy < 0 || dx>=r || dy>=c || visit[dx][dy]) continue;
                    if(board[dx][dy] == '.') continue;
                    Q.push({dx,dy});
                    visit[dx][dy] = true;
                }
            }
            cnt++;
        }
    }
    
    for(int x=r-2; x>=0; x--) {   //땅바닥에 붙어있지 않은 클러스터를 집합에 추가
        for(int y=0; y<c; y++) {
            if(visit[x][y] == false && board[x][y] == 'x') {
                queue<pair<int,int>> Q;
                Q.push({x,y});
                S[y].insert(x);
                visit[x][y] = true;
                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int dx = cur.first + ddx[dir];
                        int dy = cur.second + ddy[dir];
                        if(dx<0 || dy < 0 || dx>=r || dy>=c || visit[dx][dy]) continue;
                        if(board[dx][dy] == '.') continue;
                        Q.push({dx,dy});
                        S[dy].insert(dx);
                        visit[dx][dy] = true;
                    }
                }
                cnt++;
            }
        }
    }
    return cnt;
}


int main() {
    cin >> r >> c;
    for(int x = 0; x < r; x++) {
        string s; cin >> s;
        for(int y = 0; y < c; y++) {
            board[x][y] = s[y];
        }
    }
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0 ; i < n; i++) {
        int num = arr[i];
        remove(num,i%2);
        map<int,set<int,greater<int>>> S; //클러스터 좌표
        cluster(S);
        int minlen = INT_MAX;
        for(auto z : S) {
            int len = 0;
            int curY = z.first;
            int curX = *(z.second.begin());
            for(int i = curX+1; i < r; i++) {
                if(board[i][curY] == '.') len++;
                else break;
            }
            minlen = min(minlen,len);
        }
        for(auto z : S) {
            int curY = z.first;
            for(auto zz : z.second) {
                board[zz][curY] = '.';
                board[zz+minlen][curY] = 'x';
            }
        }
        
    }
    for(int x=0; x<r; x++) {
        for(int y=0; y<c; y++) {
            cout << board[x][y];
        }
        cout<<'\n';
    }




=======
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int r,c; 
int ddx[4] = {1,0,-1,0};
int ddy[4] = {0,-1,0,1};
char board[101][101];


void remove(int row,int dir) {
    row = r - row;
    if(!dir) {
        for(int i = 0; i < c; i++) {
            if(board[row][i] == 'x') {
                board[row][i] = '.';
                return;
            }
        }
    } else {
        for(int i = c-1; i >= 0; i--) {
            if(board[row][i] == 'x') {
                board[row][i] = '.';
                return;
            }
        }
    }
}

int cluster(map<int,set<int,greater<int>>> & S) {
    int cnt = 0;
    int visit[101][101] = {0};

    for(int y = 0; y < c; y++) { //땅바닥 붙어있는 놈들 방문처리.
        int x = r-1;
        if(visit[x][y] == false && board[x][y] == 'x') {
            queue<pair<int,int>> Q;
            Q.push({x,y});
            visit[x][y] = true;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int dx = cur.first + ddx[dir];
                    int dy = cur.second + ddy[dir];
                    if(dx<0 || dy < 0 || dx>=r || dy>=c || visit[dx][dy]) continue;
                    if(board[dx][dy] == '.') continue;
                    Q.push({dx,dy});
                    visit[dx][dy] = true;
                }
            }
            cnt++;
        }
    }
    
    for(int x=r-2; x>=0; x--) {   //땅바닥에 붙어있지 않은 클러스터를 집합에 추가
        for(int y=0; y<c; y++) {
            if(visit[x][y] == false && board[x][y] == 'x') {
                queue<pair<int,int>> Q;
                Q.push({x,y});
                S[y].insert(x);
                visit[x][y] = true;
                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int dx = cur.first + ddx[dir];
                        int dy = cur.second + ddy[dir];
                        if(dx<0 || dy < 0 || dx>=r || dy>=c || visit[dx][dy]) continue;
                        if(board[dx][dy] == '.') continue;
                        Q.push({dx,dy});
                        S[dy].insert(dx);
                        visit[dx][dy] = true;
                    }
                }
                cnt++;
            }
        }
    }
    return cnt;
}


int main() {
    cin >> r >> c;
    for(int x = 0; x < r; x++) {
        string s; cin >> s;
        for(int y = 0; y < c; y++) {
            board[x][y] = s[y];
        }
    }
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0 ; i < n; i++) {
        int num = arr[i];
        remove(num,i%2);
        map<int,set<int,greater<int>>> S; //클러스터 좌표
        cluster(S);
        int minlen = INT_MAX;
        for(auto z : S) {
            int len = 0;
            int curY = z.first;
            int curX = *(z.second.begin());
            for(int i = curX+1; i < r; i++) {
                if(board[i][curY] == '.') len++;
                else break;
            }
            minlen = min(minlen,len);
        }
        for(auto z : S) {
            int curY = z.first;
            for(auto zz : z.second) {
                board[zz][curY] = '.';
                board[zz+minlen][curY] = 'x';
            }
        }
        
    }
    for(int x=0; x<r; x++) {
        for(int y=0; y<c; y++) {
            cout << board[x][y];
        }
        cout<<'\n';
    }




>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}