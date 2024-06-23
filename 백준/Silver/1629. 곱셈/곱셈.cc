#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

//a^n*a^n = a^2n..
//나머지 분배법칙.
//홀수면 -1, 짝수면 1/2 으로 줄여나가기.
long long powermod(long long a,long long b,long long m){//a^b%m을 구함.
    if(b==1){
        return(a%m);
    } else if(b%2 == 1){ //홀수면
        return ((a%m)*powermod(a,b-1,m))%m;
    } else {
        long long p = powermod(a,b/2,m);
        return ((p*p)%m);
    }
}

int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    long long A,B,C;
    cin >> A >> B >> C;

    if(A==1){
        cout << A%C;
        return 0;
    } else if(C==1){
        cout << 0;
        return 0;
    }

    cout << powermod(A,B,C);



    
    return 0;
}


