#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
 
//동생에서 부터 탐색을 해도 결국 겹치는건 같기에... 방문 배열을 따로 관리해줘야 함..

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int X,Y;
    cin>>X>>Y;

    if(X==Y) {
        cout<<0;
        return 0;
    }


    vector<vector<bool>> visit(2,vector<bool>(500001,0)); 
    queue<int> Q;
    queue<int> tempq;
    int time = 0;

    tempq.push(X); //index 만큼의 시간이 지남을 의미.
    visit[0][X]  = 1;

    while(!Q.empty() || !tempq.empty()){ //횟수가 다 되면 죽음이다.
        if(Q.empty()){
            
            swap(Q,tempq);
            time++;
            Y+=time;
            if(Y>500000) break;
            if(visit[time%2][Y]){
                cout<<time;
                return 0;
            }
        }

        int cur = Q.front(); Q.pop();
        int nows[] = {cur*2,cur-1,cur+1};

        for(int i = 0; i < 3; i++){ // 0 1 2
            int now = nows[i];
            if(now<0||now>500000) continue;
            if(visit[time%2][now]) continue;

            if(now == Y){ //같으면 지금 시간 출력
                cout<<time;
                return 0;
            }

            visit[time%2][now] = 1;
            tempq.push(now);
        }
        

    
    }

         

    
    cout<<-1;
    



    return 0;
}