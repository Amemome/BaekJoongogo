#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
 //방문한 곳을 체크할 배열  전역이라서 0으로 초기화
    //배열의 크기 ,체크용
int dx[4]={1,0,-1,0};  //상하좌우 검사할 떄 필요
int dy[4]={0,1,0,-1};

int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int x,y;
    cin >> x >> y;

    int count = 0; //그림의 개수를 카운트합니다.
    bool visit[502][502] = {0};
    int realmax = 0;

    int board[502][502] = {0};
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){  //board 요소들 순회 board[i][j]
            int now = board[i][j];
            if (board[i][j] == 1 && visit[i][j] == 0){   //board 에 색칠된게 있고, 방문하지 않아야 순회를 함.
                count++;
                int max = 1;
                queue<pair<int,int> > Q;
                visit[i][j] = 1;
                Q.push({i,j});

                while(!Q.empty()){ //Q의 큐가 비면 전부 돈 것.
                    pair<int,int> current = Q.front(); Q.pop(); //먼저 들어온걸 현재에넣고 pop
                    for(int d = 0; d < 4; d++){  //상하좌우 searching
                        int searchX = current.first+dx[d];
                        int searchY = current.second+dy[d];
                        if(searchX < 0 || searchY < 0 || searchX >= x || searchY >= y) continue;
                        if(visit[searchX][searchY] || board[searchX][searchY] != 1) continue;
                        visit[searchX][searchY] = 1;
                        max++;
                        Q.push({searchX,searchY});
                    }    
                }
                if (max > realmax) {
                    realmax = max;
                }

            }

            
        }
        
    }
    cout << count  << "\n" << realmax ;
    return 0;
}



