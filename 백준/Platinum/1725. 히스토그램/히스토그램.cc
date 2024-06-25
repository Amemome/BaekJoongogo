#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>

using namespace std;

//일단 스택 받는대로 하면 될 거 같고
//흠 n 번째에 h 이라는 높이가 들어오면, 이 높이를 기준으로 계속...보면서 나보다 작은게 오면 끝? 이라는 느낌.
//일단 이걸로 하고. index 남기는게 매우 중요한듯.



int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int X;
    cin >> X;

    long long count = 0;

    stack<pair<int,int>> stack;

    long long max = 0;
    stack.push({0,0});

    for(int i = 1; i <= X+1; i++){
        
        int n;
        cin >> n;
        if(i == X+1) n = 0;

        while(1){
            if(stack.top().second == 0){ //비어있으면? 그냥 끝에 오면,
                stack.push({n,i}); //first 높이 / second index
                break;

            } else if(stack.top().first < n) {  // 크면푸시
                stack.push({n,i});
                break;
            } else if(stack.top().first >= n) { //pop 을 하는데 지금의 index, pop 하려고 하는 막대기의 index 그리고 pop을 한 뒤에 의 top 의 index 가 필요함
                int popnow = stack.top().first;    //그 세개의 인덱스가 있을 때 그 인덱스 사이의 값들 +1 이 막대기로볼수잇다. 
                int index = stack.top().second;
                stack.pop();
                long long area = popnow*((i - index - 1) + (index - stack.top().second));

                if (max < area) max = area;

                }        
            }
    
    } // 위의 과정을 다 수행했으면, 오름차순으로 정렬이 되어 있을 것.
    //하지만 마지막에 0이 나오는게 아닌 이상.. 높이가 제일 작은 케이스를 보지 못했음. 그래서 그걸 계산한다.

    cout << max;
    return 0;
}


