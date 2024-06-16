#include <iostream>


using namespace std;

long long gcd(long long x,long long y);

int main(){ 

    long long result = 0;
    long long N,M;
    cin >> N >> M;

    long long ggg = gcd(N-1,M-1);

    long long ratio_N = (N-1)/ggg;
    long long ratio_M = (M-1)/ggg;

    long long rane = ratio_N*ratio_M*(ggg-1);  // between nodes' length if gcd is 1 no length.

    long long nodes;



    N = N - ratio_N*(ggg-1);
    M = M - ratio_M*(ggg-1);



    if ((N-1)%2 == 0) {
        nodes = (N)*(M/2);
    } else if((M-1)%2 ==0) {
        nodes = (M)*(N/2);
    } else {
        nodes = (N)*(M/2);
    }

    result = nodes + rane;

    
    cout << result;
        
    return 0;
}


long long gcd(long long x, long long y){
    if(y==0) return x;
    return gcd(y,x%y);
}
