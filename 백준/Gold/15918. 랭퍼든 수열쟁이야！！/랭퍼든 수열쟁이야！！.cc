#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

int seq[30]; //1~ 2*n 
int nums[15]; // 1 ~ n
int result;
int n,x,y,s;

void search(int depth) { //depth 가 n을 나타냄. n을 배치하기.
    if(depth == 0) {
        result++;
        return;
    }
    if(depth == s) {
        search(depth-1);
    }
    
    for(int i = 1; i+depth+1 <= 2*n; i++) {
        if(seq[i] == 0 && seq[i+depth+1] == 0) {
            seq[i] = seq[i+depth+1] = depth;
            search(depth-1);
            seq[i] = seq[i+depth+1] = 0;
        }
    }
    return;
}

//채워져 있는 것을 어떻게 처리해야할까? 그냥 채워진 배열을 줘?


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
     cin >> n >> x >> y;

    s = y - x - 1; //뭐가 채워짐?

    seq[y] = seq[x] = s;

    //for(int i = 0; i<= 2*n ; i++) cout << seq[i] << ' ';

    search(n);


    cout << result;

    return 0;
}