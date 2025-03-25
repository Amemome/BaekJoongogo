#include <iostream>
#include <vector>
#include <queue>
#include<cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <numeric>

#define ref(i,n) for(int i = 0; i < n; i++)
#define INF 1e9
using namespace std;

//5350

vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41}; //long long 범위의 검사를 하기 위한 

long long bmult(long long a, long long b, long long mod){
    a = a %mod;
    b = b %mod;

    unsigned long long result = 0;
    unsigned long long para = b;

    while(a) {
        if(a%2) result = (result+para)%mod;
        para = (para << 1) % mod;
        a >>= 1;
    }
    return (long long) result;
}

long long powmod(long long a, long long p, long long mod) {
    long long result = 1;
    a %= mod;

    while(p){
        if(p%2) result = bmult(result,a,mod);
        a = bmult(a,a,mod);
        p >>= 1;
    }
    return result;
}

long long power(long long a, long long p) {
    long long result = 1;
    while(p--){
        result *= a;
    }
    return result;
}

bool mr(long long n, long long a){
    long long k = n - 1;

    while(1){
        long long d = powmod(a,k,n);
        if(k%2) return (d==1 || d==n-1);
        if(d==n-1) return true;
        k >>= 1;
    }
}

bool isprime(long long n){
    if (n==1) return false;
    for(auto x : primes) {
        if(n == x) return true;
        if(n % x == 0) return false;
        if(!mr(n,x)) return false;
    }
    return true;
}

vector<long long> pr;

long long f(long long x,long long a, long long n){
    return (bmult(x,x,n)+a+n)%n;
}

long long phro(long long n){
    if(isprime(n)) return n; //소수
    
    if(n==1) return 1;
    if(n%2==0) return 2;

    long long x = rand() % (n - 2) + 2;
    long long y = x;
    long long a = rand() % (n - 1) + 1;
    long long z = 1;

    while(z == 1){
        x = f(x,a,n);
        y = f(y,a,n);
        y = f(y,a,n);
        z = gcd(abs(x-y),n);

        if(z==n) return phro(n);
    }
    if(isprime(z)) return z;
    else return phro(z);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n ;
    cin >> n;

    map<long long,int> result;

    while(n>1){
        long long d = phro(n);
        result[d]++;
        n /= d;
    }



    long long r = 1;
    for(auto x : result){
        r *= power(x.first,x.second) - power(x.first,x.second-1);
    }
    cout << r;


    return 0;
}

