#include <iostream>
#include <vector>
#include <stack>
#include <utility>



using namespace std;

//스택 스택 스택 스택 스택 스택 스택 스택 2 4 1 2 2 5 1
// 일단 처음걸 뽑음 이걸 top 이라고 두자. 그리고,다음거부터 스택에 넣습니다.   x는 위에서 x 번째 수.
// 1이 있으면 5를 넣음. 근데 넣기 전에 비교를 해봐야해요  top < people[x+1]을 하고 이게 맞으면 탈출
//아니면 계속합니다. 두번째 부터는 top[x] 랑 top [x+1] 비교하기
//스택 에 넣은걸 어떻게 써먹냐


//인덱스 값은 그냥 스택에 넣을때 같이 넣어줘도 될듯.
//이게 처음부터 스택에 넣음. 역대 최대를 갱신해줌..

//높이가 같을 때 어떻게 받는지 좀 궁금한데.... 일단 같아도 받는걸로 생각 안해봄.

//스택에 값을 넣기 전에 검사를 함. top 을 검사합니다. 지금 입력받은 z 가 top 보다 작거나같으면 추가 안하고 인덱스 출력.
//z가 top 보다 크면 

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int N;
    cin >> N;

    stack<pair<int,int>> stack; //입력값 저장할 스택

    int z;


    stack.push({0,0});


    for(int i = 1; i < N+1; i++){
        cin >> z;
        
        while(1) { //스택을 검사합니다..
            if(stack.top().second < z) { //top 이 z 보다 작을때
                if (stack.top().second == 0) {
                    cout << "0 " ;
                    break;
                } else {
                stack.pop();
                }
                
            } else {           //top 이 z 보다 클때?!?!
                cout << stack.top().first << " ";
                break;
            }
              
        }
        stack.push({i,z}); 
    }

    return 0;
}



