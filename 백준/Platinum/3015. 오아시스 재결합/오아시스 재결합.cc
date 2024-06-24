#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>

using namespace std;

//순서 상관없이 스택에 추가. 그냥 오는대로 받자 근데 top  보다 큰 수가 들어오면
//top 에 있는 숫자랑 pair 가 될 수 있는게 없음 그래서 pop 해줌.
//근대 이제 pair 세는게 문제인데. 옆에 붙어있으면 무조건 볼 수는 있어서..
//두 가지의 생각을 해봄 1.양옆에 잇는 pair 빼고 계산, or 같이 계산.
//2 4 1 2 2 5 1 예제를 보면,
//2 가 들어옴 일단. 그리고 4가 2보다 크니까 2를 pop  하고 4가 들어갑니다.
//스택에 4밖에 없음 여기서 1이 들어오고 <4,1>이 되는데, 여기서 2를 어떻게 할것이냐
//2는 4랑 1 을 둘다 볼 수 있음.. "둘 사이에 둘보다 큰수가 없어야함."
//그럼 여기서 생각 해볼 수 있는게 8 5 2 가 있다고 하자. 4가 들어오면 어떻게 할거임?
//4가 들어오면 5랑 2만 되겠죠 그러면 

//그럼 일단 마지막에 pair 들 더하는걸로 ㄱㄱ
//제일 난관이... 키가 같을떄 인데 그냥 스택 하나 더 만들어서 스택에 넣어버려?

//ㅁㄹ 뭘 해도 안되네 같은 값을 처리할 때, 그 해시처럼 66653 면 (6,3),(5,1),(3,1) 이렇게 ㄱㄱ
int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int X;
    cin >> X;

    long long count = 0;

    stack<pair<int,int>> stack;


    for(int i = 0; i < X; i++){

        int n;
        cin >> n;

        int temp;
        
        while(1){

            
                               
            if(stack.empty()){ ;
                stack.push({n,1});    //first 는 키, second 는 몇개가 연속인지.
                break;
            }

            if (stack.top().first < n){
                count += stack.top().second;
                stack.pop();

            } else if(stack.top().first==n){  //n이랑 같은게 연속된다? 그러면 무조건 당므엔 큰게 나옴.
                if(stack.size() == 1){ //만약 다 빼버리면 empty 다
                    count += stack.top().second;
                } else {
                count += stack.top().second+1;
                }
                temp = stack.top().second+1; //1 추가한걸로다가 만들어줌.

                stack.pop();  //빼주고 second에 하나더한걸로추가
                stack.push({n,temp});

                break;

            } else {          //큰거 만나면

                count += 1;
                stack.push({n,1});

                break;
            }
        }
    }
    


    cout<<count;



    

    return 0;
}


