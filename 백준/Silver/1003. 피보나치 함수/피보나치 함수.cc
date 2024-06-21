#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//피보나치 함수에서 끝에서 0과 1이 나오는 횟수를 출력.
//3 은 1 2 
//4 는 
//pair 로 잘 하면 될 거 같음. 
//0 1 0    1  0 1  2 
int main(){ 

    int N;
    cin >> N;
    

    int MAX = 0;
    int inps[N] = {0};
    for (int i = 0; i < N; i++){
        int X;
        cin >> X;
        inps[i] = X;
        if (MAX < X) MAX  = X;
    }

    vector<pair<int,int>> fibo(MAX+2);

    fibo[0] = {1,0};
    fibo[1] = {0,1};
    for(int i = 2;i<=MAX;i++){
        fibo[i]= {fibo[i-1].first + fibo[i-2].first, fibo[i-1].second + fibo[i-2].second};
    }

    for(auto X:inps){
        cout << fibo[X].first << " " << fibo[X].second << "\n";
    }
    
    
    
    return 0;
}



