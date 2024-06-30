#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
 
//일단 판이 하나니까 방문처리 배열은 하나만 있어도 될듯
//플레이어 1...2..
//몇번을 할수있는지도 있는데..흠 끝날ㄴ 때 까지 정지 안됨. 
//플레이어 n 이 m 번의 턴을 가져간다고 생각한다.

// 종료조건<<큐가 다 비었으면..
//프로세스: 플레이어 1이 N 만큼 확장함 -> 플레이어 2가 M 만큼 확장함 -> 플레이어 1이 N 만큼 확장함.
//반복하다가 더이상 확장할 수 없으면 종료. 그리고 출력.

//플레이어1 templay 배열에서 저장을 해옴..

//대충 만들었는데 플레이어 2가 두번해버리는 문제 발생.
struct pos{
    int x,y;
    pos(int x,int y) :  x(x), y(y) {}
};

bool allemtpy(vector<queue<pos>> temp){
    for(auto q:temp){
        if(!q.empty()) return 0; 

    }
    return 1;
}



int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int X,Y,P;
    cin>>X>>Y>>P;
    vector<int> players(P,0);

    for(int i = 0; i < P; i++){
        cin>>players[i]; //i 번째 플레이어가 몇번의 턴을 가질 수 있는가?
    }
    
    
    vector<vector<int>> board(X,vector<int>(Y,0));
    vector<vector<bool>> visit(X,vector<bool>(Y,0));
    vector<queue<pos>> temp(P);
    vector<int> count(P,0); //영역을 세는 ....
    queue<pos> Q;
    
    for(int x = 0; x < X; x++){
        for(int y = 0; y < Y; y++){
            char i;
            cin>> i;

            if(i=='#') board[x][y] = -1;
            else if (i=='.') board[x][y] = 0;
            else {
                int n = i-'0';
                board[x][y] = n;
                visit[x][y] = 1;
                temp[n-1].push(pos(x,y));
                count[n-1]++; //영역 ++ 해줌
                }
        }
    }


    int nowplayer = 0; //지금 움직일 수 있는 플레이어를 의미
    int turn = 0; //지금의 진행된 턴을 의미
    
    while(1){

        if(Q.empty()){ //시간, 즉 턴이 하나 지났다.
                    if(allemtpy(temp)){
                for(auto qwe : count){
                    cout<< qwe << " ";
                    cout<<flush;
                    
                }
                break;
            }

            if(turn==players[nowplayer] || temp[nowplayer].empty()){
                nowplayer = (nowplayer+1)%P; //다음플레이어.
                turn = 0; //턴 초기화.
                continue;
            } else {
                
                swap(Q,temp[nowplayer]);
                
                turn++;
                if(Q.empty()) continue;
            }
        }
        pos cur = Q.front();
        Q.pop();

        for(int dir = 0; dir<4; dir++){
            int nx = cur.x+dx[dir];
            int ny = cur.y+dy[dir];

            if(nx<0||ny<0||nx>=X||ny>=Y) continue;
            if(visit[nx][ny] || board[nx][ny] != 0) continue;
            board[nx][ny] = board[cur.x][cur.y];
            visit[nx][ny] = 1;
            count[nowplayer]++;
            temp[nowplayer].push(pos(nx,ny));
        }

    

    }



    
    
    return 0;
}