#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int count1 = 0;
int RGcount = 0;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

char rgb[101][101];
bool visit[101][101];
bool visit2[101][101];

void search(char color,int x,int y){
    queue<pair<int,int>> Q;
    count1++;

    visit[x][y] = 1;
    Q.push({x,y});
    while(!Q.empty()){
        pair<int,int> cur = Q.front();Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx= cur.first+dx[dir];
            int ny = cur.second+dy[dir];
            if(nx<0||ny<0||nx>=N||ny>=N) continue;
            if(visit[nx][ny] == 1|| rgb[nx][ny] != color) continue;
            visit[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
}



//적록색약 아니면 그냥 따로 BFS 돌리고..
//적록색약이면 G랑R이랑 합쳐서 BFS 돌리고

int main(){


    
    cin >> N;
    for(int i = 0;i<N;i++){
        string s;
        cin>>s;

        for(int j = 0;j<N;j++){
            rgb[i][j] = s[j];
        }
    }

    

    for(int x = 0;x<N;x++){    //적록색 X
        for(int y = 0;y<N;y++){
            if(rgb[x][y] == 'R' && visit[x][y] == 0) {
                search('R',x,y);
            } else if (rgb[x][y] == 'G' && visit[x][y] == 0){
                search('G',x,y);
            } else if (rgb[x][y] == 'B' && visit[x][y] == 0){
                search('B',x,y);
            }
        }
    }

    cout<<count1<<" ";

    count1=0;


    
    for(int x = 0;x<N;x++){    //적록색 X
        for(int y = 0;y<N;y++){
            if(rgb[x][y] == 'R') rgb[x][y] = 'G';
            visit[x][y] = 0;
        }
    }

    for(int x = 0;x<N;x++){    //적록색 0
        for(int y = 0;y<N;y++){
            if(rgb[x][y] == 'G' && visit[x][y] == 0) {
                search('G',x,y);
            } else if (rgb[x][y] == 'B' && visit[x][y] == 0){
                search('B',x,y);
            }
        }
    }

    cout<<count1;

    




    return 0;
}