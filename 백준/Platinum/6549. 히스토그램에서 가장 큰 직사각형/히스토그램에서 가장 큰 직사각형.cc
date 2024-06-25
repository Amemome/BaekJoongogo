#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>

using namespace std;

//일단 스택 받는대로 하면 될 거 같고
//흠 n 번째에 h 이라는 높이가 들어오면, 이 높이를 기준으로 계속...보면서 나보다 작은게 오면 끝? 이라는 느낌.
//일단 이걸로 하고. index 남기는게 매우 중요한듯.

    void histo(int X){




        stack<pair<int,int>> stack; 

        long long max = 0;          
        stack.push({0,0});         

        for(int i = 1; i <= X+1; i++){ 
            int n;
            if(i==X+1){
                n = 0;
            } else {
                cin >> n;
            }



            while(1){
                if(stack.top().second == 0){ 
                    stack.push({n,i}); 
                    break;

                } else if(stack.top().first < n) { 
                    stack.push({n,i});
                    break;
                } else if(stack.top().first >= n) { 
                    int popnow = stack.top().first; 
                    int index = stack.top().second; 
                    stack.pop();
                    long long area = ((long long) popnow)*((i - index - 1) + (index - stack.top().second)); 

                    if (max < area) max = area;

                    }        
                }
            }
            cout << max << "\n";
        }


int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);


    while(1){
        int S;
        cin >> S;
        if(S == 0) break;
        histo(S);
    }
    
    return 0;
}


