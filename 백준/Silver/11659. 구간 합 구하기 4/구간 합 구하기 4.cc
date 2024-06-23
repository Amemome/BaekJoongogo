#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

// 2xN 이니까.. 타일의 가짓수는 세로로 하나. 또는 가로로 두개. 이렇게 해서 1 or 2 칸을 먹으면서 진행함.
//1 + 2 + 2 + 1 ... 이런 식으로 표현하면 될 듯?
//ㄴ


int main(){ 

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
 

    int N,M;
    cin >> N >> M;

    int *arr = new int[N+1];

    for(int i = 1; i <= N; i++){
        int num;
        cin >> num;
        
        arr[i] = arr[i-1]+num;

    }

    for(int i = 0; i < M; i++){
        int left,right;
        cin >> left >> right;
        cout << arr[right] - arr[left-1]<<"\n";
    }

    delete[] arr;
    return 0;
}


