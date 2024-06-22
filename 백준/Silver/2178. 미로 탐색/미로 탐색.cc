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
    cin >> X >> Y;
    


    bool visit[102][102] = {0};
    int board[102][102] = {0};
    
    for(int x = 0; x < X; x++){
        string line;
        cin >> line;
        for(int y = 0; y < Y; y++){
            board[x][y] = line[y] - '0';
        }
    }

 


    queue<pair<int,int> > Q;
    visit[0][0] = 1;
    Q.push({0,0});

    while(!Q.empty()){ //Q의 큐가 비면 전부 돈 것.
        pair<int,int> current = Q.front(); Q.pop(); //먼저 들어온걸 현재에넣고 pop
        for(int d = 0; d < 4; d++){  //상하좌우 searching
            int searchX = current.first+dx[d];
            int searchY = current.second+dy[d];
            if(searchX < 0 || searchY < 0 || searchX >= X || searchY >= Y) continue; //범위초과 잡기.
            if(visit[searchX][searchY] || board[searchX][searchY] == 0) continue;
            

            board[searchX][searchY] = board[current.first][current.second] + 1;

            visit[searchX][searchY] = 1;
        
            Q.push({searchX,searchY});
        }
    }


    cout << board[X-1][Y-1];

    return 0;
}



