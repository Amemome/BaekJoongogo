#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

//아마도...... N 으로 가는 제일 빠른 방법은 그 칸으로 가는 사다리를 타는 것이 아닌가...
//사다리나 뱀을 어떻게 구현해야 하는가? 지금 갈 곳, nx 가 snake 나 ladder vector 의 안에 있는 무언가인가?
//탐색을 돌려서 true 면 이동하는걸로.
int main(){

    int N,M;
    
    cin >> N >> M;

    bool visit[111] = {0};
    int game[111] = {0};

    fill(game,game+111,100);

    vector<pair<int,int>> ladder;
    vector<pair<int,int>> snake;

    int f,s;
    for(int i = 0; i < N; i++){
        cin>>f>>s;
        ladder.push_back({f,s});
    }
    for(int i = 0; i < M; i++){
        cin>>f>>s;
        snake.push_back({f,s});
    }

    queue<int> Q;
    visit[1] = 1;
    game[1] = 0;
    Q.push(1);

    while(!Q.empty()){
        int current = Q.front(); Q.pop();

        for(int i = 1; i <= 6; i++){
            int nowx = current + i;
            if(nowx>100) continue;
            if(visit[nowx]) continue;



            visit[nowx] = 1;
            
            for(auto X: ladder){
                if(X.first == nowx) nowx = X.second;
            }
            for(auto X: snake){
                if(X.first == nowx) nowx = X.second;
            }

            if(game[current] + 1 < game[nowx]) game[nowx] = game[current] + 1;
            visit[nowx] = 1;

            Q.push(nowx);
        }
    }

    cout<<game[100];

    return 0;
}