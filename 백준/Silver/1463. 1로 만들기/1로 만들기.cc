#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

//점화식? 3으로 나눠지면 3, 2로 나눠지면 2 그냥 1빼기.... 각 상태에 따라서 근데
//최소값 어떻게 찾음 어차피 메모리에서 가져와서 더하는.. 최소 3*배열크기 시간밖에 안걸림?

int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int N;
    cin >> N;

    int dist[1000002] = {0}; //회수의 최솟값을 구함. 배열에는 최솟값을 넣음.
    
    dist[2] = 1;
    dist[3] = 1;
    for(int i =4; i<=N; i++){
        int three = 1000000, two = 1000000, one = 1000000;
        if (i%3==0) {
            three = dist[i/3] + 1;
        }

        if (i%2==0) {
            two = dist[i/2] + 1;
        }

        one = dist[i-1] + 1;

        int min = (one<two)? one: two;
        dist[i] = (min < three)? min: three;
    }

    cout << dist[N];
    
    return 0;
}


