#include <iostream>
#include <vector>
#include <stack>
#include <utility>



using namespace std;


//막히는 부분까지 볼 수 있다고 합니다.
//
int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int N;
    cin >> N;

    stack<int> inputstack;
    stack<pair<int,int>> stack; //입력값 저장할 스택

    int z;
    long long count = 0;

    for(int i = 0; i < N; i++){
        cin >> z;
        inputstack.push(z);    //input stack 에 선입선출.
    }

    int top;
    stack.push({0,0});

    for(int i = 0; i < N; i++){
        z = inputstack.top();
        inputstack.pop();

        while(1) { //스택을 검사합니다..
            if(stack.top().second < z) { //top 이 z 보다 작을때 일단 push 햇으니까. 작으면,
                if (stack.top().second == 0) { //무한의 눈물
                    count += i;
                    break;
                } else {
                    stack.pop();
                }
                
            } else {           //top 이 z 보다 클때?!?!
                count += i - stack.top().first - 1;
                break;
            }
              
        }
        stack.push({i,z});
    }

    cout << count;

    return 0;
}



