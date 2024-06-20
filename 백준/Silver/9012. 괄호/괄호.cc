#include <iostream>
#include <stack>
#include <string>


using namespace std;
int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int N;
    cin >> N;

    
    string blace;


    for(int i =0;i < N; i++){
        stack<char> stack;     //스택을 for문 블록 바깥에다 정의하면 잔여 괄호들이 남아있음..
        cin >> blace;
    
        for(auto x:blace){
            //비어있냐 먼저 검사. 비어있으면 break.
            if (stack.empty()){
                stack.push(x);
            } else if ((stack.top() == '(') && (x == ')')) { //안비어있지? top 에 (이 잇고 )인지확인.
                stack.pop();
            } else {
                stack.push(x);
            }
        }
        
        if (stack.empty()){
            cout<<"YES";
        } else {
            cout <<"NO";
        }
        cout << "\n";

    }
    return 0;
}



