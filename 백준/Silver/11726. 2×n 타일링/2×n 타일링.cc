#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

// 2xN 이니까.. 타일의 가짓수는 세로로 하나. 또는 가로로 두개. 이렇게 해서 1 or 2 칸을 먹으면서 진행함.
//1 + 2 + 2 + 1 ... 이런 식으로 표현하면 될 듯?
//ㄴ


int main(){ 

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
 

    int N;
    cin >> N;

    int tile[1002];

    tile[1] = 1;
    tile[2] = 2;

    for(int i = 3; i<=N; i++){
        tile[i] = tile[i-1]%10007+tile[i-2]%10007;
    }
   
   cout<<tile[N]%10007;
    return 0;
}


