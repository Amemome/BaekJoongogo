#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

//계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
//연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
//마지막 도착 계단은 반드시 밟아야 한다.
//일단 계단을 3번 오르면 안된다고 했음.. 이것은 한칸 올라가기는 두 번 연속해서 사용하지 말라는 의미.
//이동의 방법의 수에는  .. 2 1.. 2 2 이런 세 가지로 나눌 수 있다. 그럼 N 번째 계단에는 N 까지의 최대의수를 넣으면;
//기저케이스는 다 만들어두면 됨. 1 2 3 까지는 다 만들어 진다. 
//안되네 그 한칸으로 올라왔을 때를 표시해줘야됨. 한칸으로 올라왔을 때의 최대값이랑 두컨올라왔을떄 최대값을 표시해줌.
//최댓값 1일때 최대 2일때 최대를 다 넣어주자
int main(){ 

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;

    int* stairs = new int[N+1];
    int scores[10010][2] = {0}; /// 0. 1칸으로 올라옴 .. 1. 2칸으로 올라옴..

    for(int i = 1;i <= N; i++){
        cin >> stairs[i];
    }


    scores[1][0] = stairs[1];
    scores[1][1] = 0;

    scores[2][0] = stairs[1] + stairs[2];
    scores[2][1] = stairs[2];

    for(int i = 3; i <= N; i++){
        

        scores[i][0] = scores[i-1][1] + stairs[i];
        scores[i][1] = max(scores[i-2][0],scores[i-2][1]) + stairs[i];

    }

    cout<<max(scores[N][0],scores[N][1]);

    



    delete[] stairs;
    return 0;
}


