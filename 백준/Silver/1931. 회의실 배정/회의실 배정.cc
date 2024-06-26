#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>

using namespace std;

//종료시각이 제일 빠른걸 선택. ㄱㄱ

int main(){



    int N;
    cin >> N;

    vector<pair<int,int>> confer;
    int x,y;
    for(int i = 0;i<N;i++){
        cin >> x >> y;
        confer.push_back({y,x});

    }

    sort(confer.begin(),confer.end()); //첫번째 요소 기준으로 정렬. 즉 종료시각 기준 정렬됨.

    int count = 0;
    int start = 0,end = 0;

    for(auto X:confer){

        if (X.second >= end){
            end = X.first;
            start = X.second;
            count++;
        }
    }

    cout<<count;

    

    

    return 0;
}


