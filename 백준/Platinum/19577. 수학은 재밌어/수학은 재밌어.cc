#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <algorithm>
#include <unordered_map>

#define ref(i,n) for(int i = 0; i < n; i++)
using namespace std;

bool comp(const pair<int,int> & a,const pair<int,int> & b){
    return a.second < b.second;
}

//input = n * f(n)    input 에 대해서 n이 input 의 약수니까 n 찾아서 그냥 돌리면됨.


int srs(int n){

    if(n==1) {
        return 1;
    }
    map<int,int> primes;
    int result = 1;

    for(int i = 2; i*i <= n; i++){
        while(n%i == 0) {
            primes[i]++;
            n /= i;
        }
    }
    if(n>1) primes[n]++;

    for(auto x : primes) {
        result *= pow(x.first,x.second) - pow(x.first,x.second-1); //어차피 int 범위 내라서 pow 정밀도에 안걸림
    }
    return result;
}


vector<int> prime;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    
    
    for(long long i = 1; i < 70000; i++){
        if(i*srs(i) == n) {
            cout << i;
            return 0;
            }

    } 
    cout << -1;





    
    return 0;
}