#include <iostream>
#include <vector>
#include <queue>
#include<cmath>

#define ref(i,n) for(int i = 0; i < n; i++)
#define INF 1e9
using namespace std;

long long high = 1700000000;
long long low = -1;
long long k;
int sizer = 0;
//소수의 제곱을 인수로 갖는 녀석들의 크기를 알고 싶음. 비트마스킹은 너무 커져서 안된다. 재귀 로 ㄱㄱ
//1700000000  은    1033476056 번째 제곱 ㄴㄴ수. 이정도로 범위 잡으면 될듯
//탐색하면 search(3) 일 때도 3, search(4) 일 때도 3 임. 그래서 최솟값 찾는 방향으로 ㄱㄱ

long long rere(int depth , long long index , long long num);
long long search(long long k);
vector<long long> prime;

void sieve(long long k,vector<long long> & prime){

    k = sqrt(k) + 1;
    
    vector<bool> svs(k,1);
    svs[0] = svs[1] = false;

    for(int i = 2; i*i<k; i++){
        if(!svs[i]) continue;
        for(int j = i*i; j < k; j+=i){
            svs[j] = false;
        }
        
    }
    ref(x,k){
        if(svs[x]) prime.push_back((long long)x*x);
    }
}

long long search(long long k){

    
    sizer = 0;
    for(auto x : prime) if (x <= k) sizer++;


    long long result = rere(1,0,1);
    
    
    return k - result;
}

long long rere(int depth, long long index , long long num) { //그냥 k 에 대해서 ㅇㅇ

    long long rst = 0;
    for(int i = index; i < sizer; i++) {
        long long bnum = num * prime[i];
        if(bnum > k) break;

        if(depth % 2 == 0) {
            rst -= k / bnum;
        } else {
            rst += k / bnum;
        }
        rst += rere(depth+1,i+1,bnum);
    }

    return rst;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve(1700000000,prime);

    long long s;
    cin >> s; //search 는 k 번째수 라는것을 알려줌..
    long long r;

    while(low+1 < high) {
        long long mid = (high + low) / 2;
        k = mid;
        long long nung = search(mid);

        if(s <= nung){
            high = mid;
        } else if(s > nung) {
            low = mid;
        }
        
    }
    cout << high;
    return 0;
}