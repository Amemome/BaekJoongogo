<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <queue>
#include<cmath>
#include <algorithm>
#include <map>
#include <stack>

#define ref(i,n) for(int i = 0; i < n; i++)
#define INF 1e9
using namespace std;

vector<long long> primes;

void sieves(long long n){

    n = sqrt(n) + 1;
    vector<bool> p(n+1,1);
    p[0] = 0; p[1] = 0;
    for(int i = 2; i*i < n; i++){
        if(p[i]) {
            for(int j = i*i; j <= n; j+=i) p[j] = false;
        }
    }
    for(int i = 2; i <= n; i++) {
        if(p[i]) primes.push_back(i);
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n ;
    cin >> n;

    sieves(n);


    map<long long,long long> exh;

    for(auto p : primes) {
        while(n%p == 0){
            exh[p]++;
            n /= p;
        }
    }
    if(n>1) exh[n]++;

    long long result = 1;

    for(auto x : exh){
        result *= pow(x.first,x.second) - pow(x.first,x.second-1);
    }

    cout << result;
    
    return 0;
}

=======
#include <iostream>
#include <vector>
#include <queue>
#include<cmath>
#include <algorithm>
#include <map>
#include <stack>

#define ref(i,n) for(int i = 0; i < n; i++)
#define INF 1e9
using namespace std;

vector<long long> primes;

void sieves(long long n){

    n = sqrt(n) + 1;
    vector<bool> p(n+1,1);
    p[0] = 0; p[1] = 0;
    for(int i = 2; i*i < n; i++){
        if(p[i]) {
            for(int j = i*i; j <= n; j+=i) p[j] = false;
        }
    }
    for(int i = 2; i <= n; i++) {
        if(p[i]) primes.push_back(i);
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n ;
    cin >> n;

    sieves(n);


    map<long long,long long> exh;

    for(auto p : primes) {
        while(n%p == 0){
            exh[p]++;
            n /= p;
        }
    }
    if(n>1) exh[n]++;

    long long result = 1;

    for(auto x : exh){
        result *= pow(x.first,x.second) - pow(x.first,x.second-1);
    }

    cout << result;
    
    return 0;
}

>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
