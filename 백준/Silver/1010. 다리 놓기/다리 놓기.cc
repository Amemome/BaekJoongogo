#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

struct pos{
    int x,y;
    pos(int x, int y) : x(x) , y(y) {}
};



/*
n 이랑 m 이 주어짐. 
딱 조합인데 그냥 4개 고르는 조합
m! / (n)! * (m-n)!

*/ 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long f[30] = {1,1};
    for(int i = 2; i < 30; i++) {
        f[i] = f[i-1] * i;
    }

    int k ; cin >> k;
    for(int a = 0; a < k; a++) {

        int n , m ; cin >> n >> m;

        long long result = 1;


//13 29    16 ... 29 ~ 16 / 13!
        if(n > m-n) {
            for(int i = n+1; i <= m; i++) {
                result *= i;
                
            }
            result /= f[m-n];
        } else {
            for(int i = m-n+1; i <= m; i++) {
                result *= i;
            }
            result /= f[n];
        }

        cout << result << '\n';
    }
    
    

    return 0;
}