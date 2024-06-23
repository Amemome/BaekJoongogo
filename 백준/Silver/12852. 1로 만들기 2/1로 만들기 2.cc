#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

//점화식? 3으로 나눠지면 3, 2로 나눠지면 2 그냥 1빼기.... 각 상태에 따라서 근데
//최소값 어떻게 찾음 어차피 메모리에서 가져와서 더하는.. 최소 3*배열크기 시간밖에 안걸림?

int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int N;
    cin >> N;

    int* dist = new int[N+1]; //회수의 최솟값을 구함. 배열에는 최솟값을 넣음.
    int* pren = new int[N+1];
    dist[0] = 0;
    dist[1] = 0; pren[1] = 0;
    dist[2] = 1; pren[2] = 1;
    dist[3] = 1; pren[3] = 1;
    for(int i =4; i<=N; i++){
        int three = 1000000, two = 1000000, one = 1000000;
        if (i%3==0) {
            three = dist[i/3] + 1;
        }

        if (i%2==0) {
            two = dist[i/2] + 1;
        }

        one = dist[i-1] + 1;

        int minest = min(min(one,two),three);
        if (minest == one){
            pren[i] = i-1;
        } else if (minest == two){
            pren[i] = i/2;
        } else {
            pren[i] = i/3;
        }
        
        dist[i] = minest;
    }

    cout << dist[N] << "\n" << N << " " ;

    queue<int> queue;     //pren[N] 은 다음 N 을 가리키고 다음 N
    
    while(N!=1){
        cout << pren[N] << " ";
        N=pren[N];
    }



    delete[] dist;
    delete[] pren;

    return 0;
}


