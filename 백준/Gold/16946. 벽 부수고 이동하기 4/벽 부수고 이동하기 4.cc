#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

//모든 벽에 대해서 BFS 돌리니까 시간초과...
//0에 대해서 BFS 돌리자

//0에 대해서 BFS 돌리는데 두번 적용되면 두번 더해지는 문제 발생.

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int X,Y;
    cin>>X>>Y;
    vector<vector<int>> visit(X,vector<int>(Y,0));
    vector<vector<int>> dist(X,vector<int>(Y,0));
    vector<vector<int>> board(X,vector<int>(Y,0));   //맵
    


    for(int x = 0; x < X; x++){
        string s;
        cin >> s;
        for(int y = 0; y < Y; y++){
            board[x][y] = s[y] - '0';
        }
    }


    for(int x = 0; x < X; x++){
        for(int y = 0; y < Y; y++){
            if(board[x][y] == 0 && visit[x][y] == 0) {
                set<pair<int,int>> stack;
                queue<pair<int,int>> Q;
            
                Q.push({x,y});
                visit[x][y] = 1;
                
                int count = 1;
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx<0||ny<0||nx>=X||ny>=Y) continue;
                        if(visit[nx][ny]) continue;
                        if(board[nx][ny]== 1){
                            stack.insert({nx,ny});
                            continue; 
                        }
                        count++; //통과해서 큐에 들어갔으니 한칸+된거.
                        visit[nx][ny] = 1;
                        Q.push({nx,ny});
                    } 
                }
                
                for(pair<int,int> pos : stack){
                    dist[pos.first][pos.second] += count;
                }
                

            }
        }
    }

    for(int x = 0; x < X; x++){     //보드가 1 이고 dist 가 1이상이면 +1
        for(int y = 0; y < Y; y++){ //보드가 1이고 dist 가 0이면 1으로 변신
            if(board[x][y]){
                if(dist[x][y]>0) cout<<(dist[x][y] + 1)%10;
                else cout << 1;
            } else cout << 0;
        
        }
    cout<<"\n";
    }

    
    return 0;
}