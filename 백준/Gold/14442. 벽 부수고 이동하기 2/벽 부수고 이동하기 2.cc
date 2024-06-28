#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

//괜히 거리를 2차원만 하려고 했다가 처맞음
//모든 layer. 에 대해서 visit 이랑 dist 를 저장해야할듯.


struct triple {
    int layer;
    int x;
    int y;

    triple(int layer,int x,int y) : layer(layer), x(x),y(y) {}
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int X,Y,LAYER;
    cin>>X>>Y>>LAYER;

    LAYER++; //폭파가능수 + 1 만큼 레이어가 있어야함.

    vector<vector<vector<int>>> dist(LAYER,vector<vector<int>>(X,vector<int>(Y,0)));
    vector<vector<int>> board(X,vector<int>(Y,0));   //맵
    vector<vector<vector<int>>> visit(LAYER,vector<vector<int>>(X,vector<int>(Y,0)));//방문표시. 부숨과 안부숨의 visit을 다르게.
    queue<triple> Q;

    for(int x = 0; x < X; x++){
        string s;
        cin >> s;
        for(int y = 0; y < Y; y++){
            board[x][y] = s[y] - '0';
        }
    }

for(int layer = 0; layer < LAYER; layer++){
    for(int x = 0; x < X; x++){
        for(int y = 0; y < Y; y++){
            dist[layer][x][y] = 1000000; //layer 은 폭파횟수를 n 번 쓴 것이라고 볼 수 있다.
        }
    }
}

    

    Q.push(triple(0,0,0));
    for(int i = 0; i < LAYER; i++){
        visit[i][0][0] = 1;
        dist[i][0][0] = 1;
    }

    while(!Q.empty()){
        triple cur = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx<0||ny<0||nx>=X||ny>=Y) continue;  

            //layer 에 따라서 머해야되는데. 0~k-1 까지는 폭파 가능. k 일때는 폭파 불가능.
            int ncl = cur.layer;
            if(cur.layer == LAYER - 1){ //폭파가능 다 썼나?
                
                if( visit[ncl][nx][ny] == 0 && board[nx][ny] == 0){
                    visit[ncl][nx][ny] = 1;
                    dist[ncl][nx][ny] = dist[ncl][cur.x][cur.y] + 1;
                    Q.push(triple(ncl,nx,ny));
                }

            } else if(ncl < LAYER) { //폭파가능일때.
                if( visit[ncl][nx][ny] == 0 && board[nx][ny] == 1){ //벽이라면...

                    visit[ncl+1][nx][ny] = 1;  //지금+1 까지 visit 처리
                    visit[ncl][nx][ny] = 1; //지금과
                    dist[ncl+1][nx][ny] = dist[ncl][cur.x][cur.y] + 1; //레이어 하나 올림.
                    Q.push(triple(ncl+1,nx,ny));
                } else if(visit[ncl][nx][ny] == 0 && board[nx][ny] == 0){        //벽아님.

                    visit[ncl][nx][ny] = 1;
                    dist[ncl][nx][ny] = dist[ncl][cur.x][cur.y] + 1;
                    Q.push(triple(ncl,nx,ny));
                }
            }

        }
    }

    
    int min = dist[0][X-1][Y-1];
    int cnt = 0;
    for(int i = 0; i < LAYER; i++){
        if(visit[i][X-1][Y-1]) cnt++;
        min = (min > dist[i][X-1][Y-1]) ? dist[i][X-1][Y-1] : min;
    }

    if(cnt){
        cout << min;
    } else {
        cout << -1;
    }
    
    


    
    return 0;
}