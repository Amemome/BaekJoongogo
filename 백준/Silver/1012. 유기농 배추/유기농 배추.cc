#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4]={1,0,-1,0};  //상하좌우 검사할 떄 필요
int dy[4]={0,1,0,-1};


int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int H;
    cin >> H;

    for(int aaa = 0; aaa<H; aaa++){     //H 번 케이스 실행
        int X,Y,White;
        cin >> X >> Y >> White;     //X 가로 Y 세로 whiet 배추개수
        
        int field[51][51] = {0};
        bool visit[51][51] = {0};

        for (int i = 0; i<White; i++){    //배추 개수 만큼 for 문 돌기
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;         //위치가 index 로 주어짐
        }

        int count = 0;

        for(int y = 0; y < Y; y++){
            for(int x = 0; x<X; x++){     
                if(visit[y][x] == 0 && field[y][x] == 1){ //방문한거면 안함 and 배추가 심어져있는가?
                    count++;    //방문안한 배추묶음이기 때문에 +1
                    queue<pair<int,int>> Q;
                    Q.push({y,x});
                    visit[y][x] = 1;
                    while(!Q.empty()){      //큐가 빌 때 까지, 이어져있는 부분 다 돌 때 까지.
                        pair<int,int> curr = Q.front(); 
                        Q.pop();
                        
                        for(int dir = 0; dir<4;dir++){
                            
                            int goy = curr.first + dx[dir];
                            int gox = curr.second +dy[dir];

                            if(gox<0||goy<0||gox>=X||goy>=Y) continue; //범위를 초과하는가?
                            if(visit[goy][gox]||field[goy][gox] != 1)continue; //방문했으면 and 필드에 배추가 안심어져있음?
                            
                            visit[goy][gox] = 1;
                            Q.push({goy,gox});
                        }
                    }

                    }
                    
                }
            }
            cout<<count<<"\n";
            
        }
        


    
    return 0;
}


