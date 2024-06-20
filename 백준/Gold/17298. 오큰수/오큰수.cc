#include <iostream>
#include <stack>
#include <string>


using namespace std;


//막히는 부분까지 볼 수 있다고 합니다.
//
int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int N;
    cin >> N;

    stack<int> inputstack; //입력값 저장할 스택
    stack<int> result;
    stack<int> stack;

    int z;

    for(int i = 0; i < N; i++){
        cin >> z;
        inputstack.push(z);    
    }

    stack.push(0);

    for(int i = 0; i < N; i++){
        z = inputstack.top();
        inputstack.pop();

        while(1) { //스택을 검사합니다..
            if(stack.top() <= z) { 
                if (stack.top() == 0) { 
                    result.push(-1);
                    break;
                } else {
                    stack.pop();
                }
                
            } else {           //top 이 z 보다 클때?!?!
                result.push(stack.top());
                break;
            }
              
        }
        stack.push(z);
    }

    for(int i = 0; i < N; i++){
        cout << result.top() << " ";
        result.pop();
    }

    return 0;
}



