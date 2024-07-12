#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

#define ref(i,N) for(int i = 0; i < N; i++)

struct pos{
    int x , y;
    int dir;
    pos(int dir, int x,int y): dir(dir), x(x) , y(y)  {}
};


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int N;
    cin >> N;

    vector<vector<int>> board(N,vector<int>(N,0)); //vector 을 bool 로 만들었을 때, 바로 cin>> 배열의 인덱스 가 안됨.
    vector<vector<vector<long long>>> dist(3,vector<vector<long long>>(N,vector<long long>(N,0))); //0 : 가로 / 1 : 대각선 / 2 : 세로

    ref(x,N){
        ref(y,N){
            cin >> board[x][y];
        }
    }
    ref(i,N-1){
        if(board[0][i+1]) break;
        dist[0][0][i+1] = 1;
    }

    for(int x = 1; x < N; x++){
        for(int y = 1; y < N; y++){
            
            if(!board[x][y]) {
                dist[0][x][y] += dist[0][x][y-1] + dist[1][x][y-1];
                dist[2][x][y] += dist[2][x-1][y] + dist[1][x-1][y];
                
                if(!board[x-1][y] && !board[x][y-1]){
                    dist[1][x][y] += dist[0][x-1][y-1] + dist[1][x-1][y-1] + dist[2][x-1][y-1];
                }
            }
            
        }
    
        
    }
    long long result = 0;
    for(int i = 0; i < 3; i++){
        result += dist[i][N-1][N-1];
    }
    cout<<result;

    return 0;
}