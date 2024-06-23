#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

//일단 BFS 를 돈다. for 문 돌면서, BFS 돌아줌. .. 
//돌면서, BFS 못 도는 자리, 0 이 두개 이상 있으면 "인덱스 좌표"를 스택에 저장 ㄱㄱ
//전부 다 돌면. 다음에 지워줌.
//
//문제를 잘못 이해햇었음

//외부공기를 기준으로 BFS 를 돌음. 그러면서, 치즈를 만나면 +1 을 해줌. 그리고 마지막에 for문 돌면서 2이상인거 없애줌
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int X,Y;
    cin >> X >> Y;

    int count = 0; //시간을 측정함.

    int chez[102][102] = {0};
    
    

    for(int x = 0; x < X; x++ ){
        for(int y = 0; y < Y; y++){
            cin >> chez[x][y];
        }
    }

    while(1){ 
        bool isempty = true;
        for(int x = 0; x < X; x++ ){
            for(int y = 0; y < Y; y++){
                if(chez[x][y] != 0) isempty =false;
            }
        }
            //시간이 하나 지나갈 때 마다 전체를 탐색함.
        if(isempty) break;  
        count++;
        int visit[102][102] = {0};    //시간마다 치즈가 없어지니, 방문 배열을 초기화 시켜줌.
        int melt[102][102] = {0};
        //방문한 칸이 아니여야함, 그리고 치즈가 있는 칸이여야함
        
        queue<pair<int,int>> Q;  //방문할 좌표 넣을 큐 만들어주고
        visit[0][0] = 1; //방문처리하고
        Q.push({0,0});//큐에 넣어줌

        while(!Q.empty()){

            pair<int,int> cur = Q.front(); Q.pop();

            for(int dir = 0; dir < 4; dir++){

                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx<0||ny<0||nx>=X||ny>=Y) continue;
                if (chez[nx][ny] == 1) melt[nx][ny]++;  //bfs 돌면서 치즈를 만나면 +1 해줌.
                                                    //치즈가 가장자리에는 놓이지 않는다고 했으니까 따로 검사 안해도 되겠지?
                if(chez[nx][ny] != 0 || visit[nx][ny] == 1) continue; //치즈가 있거나, 방문했거나.
                visit[nx][ny] = 1;
                Q.push({nx,ny});
            }
        }

        for(int x = 0; x < X; x++ ){
            for(int y = 0; y < Y; y++){
                if(melt[x][y]>1){     //인접 공기가 2이상이면
                    chez[x][y] = 0;  //"공기" 만들어버려
                    
                }
            }
        }
                
         //전체를 탐색했으면, melt 에 좌표들이 들어있을 것.;



    }
    cout << count;


    return 0;
}


