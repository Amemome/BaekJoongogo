#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
//visit 한거 를 체크.
int dx[4]={1,0,-1,0};  //상하좌우 검사할 떄 필요
int dy[4]={0,1,0,-1};

//불을 먼저 보내고, 그 다음에 지훈이 이동한다. queue 자료형이니까..
//불이 들어가있으면 불->지훈->불->지훈으로 될 것.
// J 에서는 숫자롤 퍼져나가고.. F 에서는 F로 퍼져나가는걸로..

int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    
    int z;
    cin >> z;
    for(int aaa = 0; aaa < z;aaa++){

    int X,Y;
    cin >> Y >> X;

    bool visit[1001][1001] = {0};  //1000x1000 으로 잡으니까 실행안돼
    int board[1001][1001] = {0};   // 제출할 떄 바꿀떄 제출....

    queue<pair<int,int>> Q;

    int jhx,jhy;
    
    for(int x = 0; x < X; x++){
        string line;
        cin >> line;
        for(int y = 0; y < Y; y++){      
            if(line[y] == '#'){
                board[x][y] = -4;
            } else if(line[y] == '.'){
                board[x][y] = -3;
            } else if(line[y] == '@'){
                board[x][y] = 1;
                jhx = x;jhy = y;
                visit[x][y] = 1;   // 방문함.
            }
            if(line[y] == '*') {
                board[x][y] = -2;
                Q.push({x,y});
                visit[x][y] = 1;
            }
        }
    }
    Q.push({jhx,jhy});

    while(!Q.empty()){
        pair<int,int> current = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; dir++){
            int px = current.first + dx[dir];
            int py = current.second+ dy[dir];
            if(px<0||py<0||px>=X||py>=Y) continue;
            if(visit[px][py]||board[px][py]== -4) continue;
            
            if (board[current.first][current.second] == -2){
                board[px][py] = -2;
            } else {
            board[px][py] = board[current.first][current.second] + 1;
            }
            visit[px][py] = 1;

            Q.push({px,py});
        }
    }

    int MIN = 10000000;


    for(int y = 0; y < Y; y++){
        board[0][y];
        if(board[0][y] < 0) continue;
        MIN = (MIN > board[0][y]) ? board[0][y] : MIN;
    }

    for(int y = 0; y < Y; y++){
        if(board[X-1][y] < 0) continue;
        MIN = (MIN > board[X-1][y]) ? board[X-1][y] : MIN;
    }

    for(int x = 0; x < X; x++){

        if(board[x][0] < 0) continue;
        MIN = (MIN > board[x][0]) ? board[x][0] : MIN;
    }

    for(int x = 0; x < X; x++){
        if(board[x][Y-1] < 0) continue;
        MIN = (MIN > board[x][Y-1]) ? board[x][Y-1] : MIN;
    }


        
    if(MIN==10000000){
        cout<<"IMPOSSIBLE";
    } else {
        cout<<MIN;
    }
    cout <<"\n";

    }
    return 0;
}



