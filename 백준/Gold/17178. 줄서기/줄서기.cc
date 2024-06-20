#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>



using namespace std;


//두 쌍을 구하는 것이니까.한쪽에서 진행하는 방향으로 하면 됨. 스택에 집어넣으면서 진행 ㄱㄱ
//2 4 1 2 2 5 1 .. 10개의 pair 가 있다. 그리고 a 와 b 사이에 a or b 보다 큰 숫자가 있으면 안됨.
/* 만약에 왼 <- 오 이렇게 짝을 지어보자.


4를 스택의 top 인 2와 비교한다  

2를 pop 하고 4를 push 한다. (2와 다른 숫자를 쌍으로 정한다고 해도, 4가 있기 때문에 서로 볼 수 없음.) pop 

!! 최대의 수가 나오면 갱신을 하는게 맞다.!!
그렇다면 작거나 같은 수가 나왔을 때는 어떻게 하나?

1을 스택의 top 인 4와 비교한다.

*/
int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int N;
    cin >> N;

    vector<int> queue;
    stack<int> stack;

    string str;
    int temp = 'A';

    for(int i = 0; i < N*5; i++){
        cin >> str;
        temp = str[0];
        str.erase(0,2);
        temp = temp*1000+stoi(str);
        queue.push_back(temp);
    }

    
    vector<int> sortedqueue(queue);
    //sortedqueue = queue;
    sort(sortedqueue.begin(),sortedqueue.end()); //여기까진 ok

    
    int index = 0;
    

    for(auto x:queue) {
        stack.push(x);
        while(1)
        {
            if(stack.top() == sortedqueue[index]){
                stack.pop();
                index++;
                if(stack.empty()) break;
            } else {
                break;
            }
        }
    }

    if(stack.empty()){
        cout << "GOOD";
    } else {
        cout << "BAD";
    }


    return 0;
}



