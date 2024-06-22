#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
//visit 한거 를 체크.
//board 를 확인하면서, board 에다가 거리로 바꿉니다. queue 에 있는 좌표. 에서 상하좌우 를 방문하며 값을 바꿈.
int dx[4]={1,0,-1,0};  //상하좌우 검사할 떄 필요
int dy[4]={0,1,0,-1};

int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int X,Y;
    cin >> Y >> X;

    int visit[1001][1001] = {0};  //1000x1000 으로 잡으니까 실행안돼
    int board[1001][1001] = {0};   // 제출할 떄 바꿀떄 제출....

    queue<pair<int,int>> Q;

    for(int x = 0; x < X; x++){
        for(int y = 0; y < Y; y++){
            
            cin >> board[x][y];
            visit[x][y] = -1;
            
            if(board[x][y] == 1){
                Q.push({x,y});
                visit[x][y] = 1;
            }
            
        }
    }

         //이게 매우 중요함.


    while(!Q.empty()){
        pair<int,int> current = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; dir++){
            int px = current.first + dx[dir];
            int py = current.second+ dy[dir];
            if(px<0||py<0||px>=X||py>=Y) continue;
            if(visit[px][py] != -1||board[px][py]!= 0) continue;
            board[px][py] = board[current.first][current.second] + 1;

            visit[px][py] = 1;

            Q.push({px,py});
        }
    }




    int max = 0;
    for(int x = 0; x < X; x++){
        for(int y = 0; y < Y; y++){

            if (max < board[x][y]) {
                max = board[x][y];
            }
            if (visit[x][y] == -1) {
                if (board[x][y] == -1){
                    continue;
                }
                cout << "-1";
                return 0;
            }
        }
        
    }
    cout<<max-1;

    return 0;
}



