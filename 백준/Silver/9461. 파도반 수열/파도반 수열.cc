#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
using namespace std;

/*

*/


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int n;
    cin >> n;
    long long seq[110] = {1,1,1,2,2,3,4,5,7,9};
    
    for (int i = 8; i < 110; i++){
        seq[i] = seq[i-1] + seq[i-5];
    }

    for (int i = 0; i < n; i++){
        int r;
        cin >> r;
        cout << seq[r-1] << '\n';
    }

    



    return 0;
}