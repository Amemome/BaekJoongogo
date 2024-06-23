#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

//일단 최솟값만 찾아가면 안된다는 것은 자명함. 그리고.. 겹치면 안되는게
//같은색이니까 3개? 2개 단위로 끊어도 될듯.


int main(){ 

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);


    int N;
    cin >> N;

    int house[1010][3];
    int cost[1010][3];
    for(int i = 1; i <= N; i ++){
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    }


    cost[1][0] = house[1][0];
    cost[1][1] = house[1][1];
    cost[1][2] = house[1][2];

    cost[2][0] = house[2][0] + min(cost[1][1],cost[1][2]);
    cost[2][1] = house[2][1] + min(cost[1][0],cost[1][2]);
    cost[2][2] = house[2][2] + min(cost[1][0],cost[1][1]);

    for(int i = 3; i <= N; i++){
        
        cost[i][0] = house[i][0] + min(cost[i-1][1],cost[i-1][2]);
        cost[i][1] = house[i][1] + min(cost[i-1][0],cost[i-1][2]);
        cost[i][2] = house[i][2] + min(cost[i-1][0],cost[i-1][1]);
    }

    cout << min (cost[N][1],min(cost[N][0],cost[N][2]));

    return 0;
}


