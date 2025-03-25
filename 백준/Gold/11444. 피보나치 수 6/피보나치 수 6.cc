#include <iostream>
#include <vector>
#include <queue>
#include<cmath>
#include <algorithm>
#include <map>


#define ref(i,n) for(int i = 0; i < n; i++)
#define INF 1e9
#define md 1000000007
using namespace std;

map<long long, long long> fibo = {{0,0},{1 , 1} , {2, 1}};

long long f(long long n) {

    long long result = 0;

    if(fibo.find(n) != fibo.end()) { //비어있지 않음.
        return fibo[n];
    }

    if(n%2) { //홀수면
        result = f((n+1)/2)*f((n+1)/2) + f((n-1)/2)*f((n-1)/2);
    } else {  //짝수면
        result = (f(n/2)) * ((f(n/2+1) + f(n/2-1)));                  //f(n/2) * ((f(n/2)+1)+f((n/2)-1));
    }

    fibo[n] = result % md;

    return fibo[n];
}

//10^18 번 연산 << 바로 죽음 N 번째 피보나치수를 어떻게 구해야 하는가.
//규칙 하나 찾음. n 번째 피보나치에서 2n 의 피보나치로 갈 때 곱해야 하는 수가 있다. 이것도 피보나치 따라감.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N;
    cin >> N;

    cout << f(N);
    

    
    


    return 0;
}