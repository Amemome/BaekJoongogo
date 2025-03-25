#include <bits/stdc++.h>
#define PNB(n) {cout << n ;return 0;}
using namespace std;
typedef long long ll;
typedef pair<double,double> pdd;
typedef pair<int,int> pii;
typedef complex<double> cd;



int main(){
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);

    int arr[10][10] = {};
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            arr[i][j] = i * 10 + j;
        }
    }
    printf("%d %d", (*(arr+1)+4), *(*(arr)+99) );
    




    return 0;
}
