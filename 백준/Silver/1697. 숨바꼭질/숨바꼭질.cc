#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
//제출한까 틀렷다고 나옴.... 반례 넣어도 다 맞는데 ㅗ애 안되지
//0 넣으니까 뭔가 고장나는 느낌? 앞에 0 들어갈때는 고쳤음.. 하지만 뒤에 0 들어가는건 해결X


int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int N,M;
    cin >> N >> M;

    queue<int> Q;

    bool visit[200001] = {0};
    int dist[200001] = {0};
    Q.push(N);
    visit[N] = 1;
    dist[N] = 0;



    while(!Q.empty()){
        
        int cur = Q.front(); 
        Q.pop();

        if(cur==M) {
            cout<<dist[cur];
            break;
        };
        
        if(N<0||N>200000) continue; //범위를 벗어나면 kill

        if((!visit[cur*2])&&(cur*2>=0)&&(cur*2<100010)) {
            Q.push(cur*2);
            visit[cur*2] = 1;
            dist[cur*2] = dist[cur]+1;
            }
        if((!visit[cur+1])&&(cur+1>=0)&&(cur+1<100010)) {
            Q.push(cur+1);
            visit[cur+1] =1;
            dist[cur+1] = dist[cur]+1;
            }
        if((!visit[cur-1])&&(cur-1>=0)&&(cur-1<100010)) {
            Q.push(cur-1);
            visit[cur-1] =1;
            dist[cur-1] = dist[cur]+1;
            }

    }

    return 0;
}


