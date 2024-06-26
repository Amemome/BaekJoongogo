#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

// 위로 쌓는건 z
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int M,N,H;
    cin>>M>>N>>H;
    
    vector<vector<vector<int>>> tomato(H, vector<vector<int>>(N, vector<int>(M, 0)));
    vector<vector<vector<int>>> how(H, vector<vector<int>>(N, vector<int>(M, 0)));
    vector<vector<vector<int>>> visit(H, vector<vector<int>>(N, vector<int>(M, 0)));

    queue<tuple<int,int,int>> Q;

    for(int z = 0; z < H; z++){
        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                int ss;
                cin >> ss;
                tomato[z][y][x] = ss;
                
                
                if(ss==1) {
                    Q.push({z,y,x});
                    visit[z][y][x] = 1;
                }
            }
        }
    }       //여기까진 ok
    
    while(!Q.empty()){
        int x,y,z;
        tie(z,y,x) = Q.front(); Q.pop();
        for(int i =0; i <6;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(nx<0||nz<0||ny<0||nx>=M||ny>=N||nz>=H) continue;
            if(visit[nz][ny][nx]==1||tomato[nz][ny][nx]!=0) continue;
            how[nz][ny][nx] = how[z][y][x] + 1;
            visit[nz][ny][nx] = 1;
            Q.push({nz,ny,nx});
        }
    }

    int max=0;

    for(int z = 0; z < H; z++){
        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                if(how[z][y][x] == 0 && tomato[z][y][x] == 0 && visit[z][y][x] == 0){
                    cout<<-1;
                    return 0;
                } else {
                    if(how[z][y][x]>max) max = how[z][y][x];
                }
            }

        }

    }

    cout<<max;
    
    
    return 0;
}