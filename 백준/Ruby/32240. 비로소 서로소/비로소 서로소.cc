#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
using namespace std;

//n * n 의 집합을 보기  

int gcd(int x , int y) {
    if(y==0) return x;
    return gcd(y,x%y);
}


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int n ;
    cin >> n;

    long long result = 2; //1+1 을 이미 한 상태

    for(int i = 1; i <= n; i++) {
        for(int x = 1; x < i; x++) {
            if(gcd(i,x) == 1) result += 2*(i+x);
        }
    }

    cout << result;


    return 0;
}