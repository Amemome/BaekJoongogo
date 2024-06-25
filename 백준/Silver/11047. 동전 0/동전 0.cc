#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>

using namespace std;

//일단 스택 받는대로 하면 될 거 같고
//흠 n 번째에 h 이라는 높이가 들어오면, 이 높이를 기준으로 계속...보면서 나보다 작은게 오면 끝? 이라는 느낌.
//일단 이걸로 하고. index 남기는게 매우 중요한듯.

int main(){

    int N,K;
    cin>>N>>K;
    
    int count = 0;
    int coins[10];

    for(int i =0;i<N;i++){
        cin >> coins[i];
    }

    for(int i = 0; i < N; i++){
        if(coins[N-i-1] <= K){
             count+= K/coins[N-i-1];
             K%=coins[N-i-1];
        }
    }

    cout<<count;

    
    return 0;
}


