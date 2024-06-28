#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

//괜히 거리를 2차원만 하려고 했다가 처맞음
//모든 layer. 에 대해서 visit 이랑 dist 를 저장해야할듯.

//밤낮 처리를 어떻게 할 것인가..
//큐를 2개 쓴다!



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

    vector<vector<vector<bool>>> blockcount(LAYER,vector<vector<bool>>(X,vector<bool>(Y,0)));
    vector<vector<vector<int>>> dist(LAYER,vector<vector<int>>(X,vector<int>(Y,0)));
    vector<vector<int>> board(X,vector<int>(Y,0));   //맵
    vector<vector<vector<int>>> visit(LAYER,vector<vector<int>>(X,vector<int>(Y,0)));//방문표시. 부숨과 안부숨의 visit을 다르게.
    queue<triple> Q;
    queue<triple> tempQ;


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
    
    for(int i = 0; i < LAYER; i++){
        visit[i][0][0] = 1;
        dist[i][0][0] = 1;
    }

    bool isDay = false;

    tempQ.push(triple(0,0,0));

    while(1){
        if(Q.empty()){ // 큐가 비었으면...
            isDay = !isDay;
            if(tempQ.empty()){ //둘다 비었으면 탈출
                break;
            }

            while(!tempQ.empty()){
                Q.push(tempQ.front());
                tempQ.pop();
            }
             //Q가 비었으면 밤낮 바꿔주기.
        }

        triple cur = Q.front(); 
        Q.pop();

        for(int dir = 0; dir < 4; dir++){//Q가 뽑혀서 4번 실행됨
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx<0||ny<0||nx>=X||ny>=Y) continue;  
            //layer 에 따라서 머해야되는데. 0~k-1 까지는 폭파 가능. k 일때는 폭파 불가능.
            int ncl = cur.layer;
            if(ncl == LAYER - 1){ //폭파가능 다 썼나?
                
                if( visit[ncl][nx][ny] == 0 && board[nx][ny] == 0){
                    visit[ncl][nx][ny] = 1;
                    dist[ncl][nx][ny] = dist[ncl][cur.x][cur.y] + 1;

                    tempQ.push(triple(ncl,nx,ny));
                }

            } else if(ncl < LAYER - 1) { //폭파가능일때.
                if( visit[ncl][nx][ny] == 0 && board[nx][ny] == 1){ //벽이라면...


                    if(isDay){
                        visit[ncl+1][nx][ny] = 1;  
                        visit[ncl][nx][ny] = 1; 
                        dist[ncl+1][nx][ny] = dist[ncl][cur.x][cur.y] + 1 +blockcount[ncl][cur.x][cur.y];
                        tempQ.push(triple(ncl+1,nx,ny));
                    } else {    //그냥 dist ++ 하니까 1이 두개 있을떄 +2 가 되어버려, 그럼 이걸 어떻게 하냐. 어차피 최단거리 찾기니까 전부 1로 두고 +1 하면 되는거아님
                        if(!blockcount[ncl][cur.x][cur.y]) {
                            blockcount[ncl][cur.x][cur.y] = true;
                        }
                        tempQ.push(cur);
                    }
                    


                } else if(visit[ncl][nx][ny] == 0 && board[nx][ny] == 0){        //벽아님.

                    visit[ncl][nx][ny] = 1;
                    dist[ncl][nx][ny] = dist[ncl][cur.x][cur.y] + 1;
                    tempQ.push(triple(ncl,nx,ny));
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