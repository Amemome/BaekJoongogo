#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

//벽을 하나만 부술 수 있음... 근데 이거 맵이 1000x1000 이네
//일단 부숴서 효과적일 수 있는 벽을 탐색하자. 0 1 0 이렇게 되어있는
//벽들을 찾아서 배열 만듬. 그리고 이 배열을 하나씩 집어넣어서
//BFS 돌림으로써 확인. 이거는 시간초과 날거같음 n 번 부수는 문제도 있는데

//벽을 부수고 난 뒤의 이동거리와, 벽을 안 부순 상태의 이동거리를 비교해야 되는데
//range 에다가... 차원 하나 더 추가해서 벽을 부숨과 안부숨을 비교해야되나?

//dist, 거리를 저장하는 배열에다가 차원을 하나 더 얹음.
//벽을 부수게 되면 "1" 의 차원으로 넘어가게 되고.. 1이면 벽을 못 부숨.
//"0" 일 때는 벽을 부숴야 하는데. 벽을 어떻게 부숴야 하나? 

//BFS 는 최단경로를 알아서 찾기 때문에... 0인 상태일 때 , if 벽을 부수는 경우를 큐에 넣어주자.
//벽을 부수면 큐에는 1,x,y 로 들어갈 것..이 상태에서는 벽을 부술 수 없게.

//visit 을 공유해도 되는게 visit 한 곳을 가면 최단경로가 아니잖음?
//근데 무조건동시진행이 될 수는 없으니. dist 를 비교해보고 ㄱㄱ.

//굳이 3차원으로 만들 필요가? 큐에다가 정보를 넣으면 되는데? 아 그러면 안되네
//3차원 visit 을 따로 만들어 줘야됨. 먼저 벽을 부수고 빨리 갔을 수 있지만, 벽을 못 부숴서 느리게 갈 수도 잇음.

//괜히 거리를 2차원만 하려고 했다가 처맞음
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

    int X,Y;
    cin>>X>>Y;

    vector<vector<vector<int>>> dist(2,vector<vector<int>>(X,vector<int>(Y,0)));
    vector<vector<int>> board(X,vector<int>(Y,0));   //맵
    vector<vector<vector<int>>> visit(2,vector<vector<int>>(X,vector<int>(Y,0)));//방문표시. 부숨과 안부숨의 visit을 다르게.
    queue<triple> Q;

    for(int x = 0; x < X; x++){
        string s;
        cin >> s;
        for(int y = 0; y < Y; y++){
            board[x][y] = s[y] - '0';
        }
    }

for(int layer = 0; layer < 2; layer++){
    for(int x = 0; x < X; x++){
        for(int y = 0; y < Y; y++){
            dist[layer][x][y] = 1000000;
        }
    }
}

    

    Q.push(triple(0,0,0)); 
    visit[0][0][0] = 1;
    visit[1][0][0] = 1;
    dist[0][0][0] = 1;
    dist[1][0][0] = 1;

    while(!Q.empty()){
        triple cur = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx<0||ny<0||nx>=X||ny>=Y) continue;
            
            if(cur.layer == 1){ //폭파했는가?

                if( visit[1][nx][ny] == 0 && board[nx][ny] == 0){
                    visit[1][nx][ny] = 1;
                    dist[1][nx][ny] = dist[1][cur.x][cur.y] + 1;
                    Q.push(triple(1,nx,ny));
                }

            } else {    //폭파안함상태
                if( visit[0][nx][ny] == 0 && board[nx][ny] == 1){ //벽이라면...

                    visit[1][nx][ny] = 1;
                    visit[0][nx][ny] = 1;
                    dist[1][nx][ny] = dist[0][cur.x][cur.y] + 1;
                    Q.push(triple(1,nx,ny));
                } else if(visit[0][nx][ny] == 0 && board[nx][ny] == 0){        //벽아님.

                    visit[0][nx][ny] = 1;
                    dist[0][nx][ny] = dist[0][cur.x][cur.y] + 1;
                    Q.push(triple(0,nx,ny));
                }

            }

        }
    }

    if(dist[0][X-1][Y-1] == 1000000 && dist[1][X-1][Y-1] == 1000000 ){
        cout << -1;
    } else{
        cout << min(dist[0][X-1][Y-1],dist[1][X-1][Y-1]);
    }


    
    return 0;
}