#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>

using namespace std;

pair<int,int> operator+(const pair<int,int>& a, const pair<int,int>& b){
    return {a.first + b.first, a.second + b.second};
}

//paper 을 void 로 해도 되겠지만,
//4개 요소의 합으로 만들어도 괜찮은게 아닌가...
//pap 의 함수는 왼쪽위를 기준으로 잡고 인수로 전달하면 n/2 만큼의
//sqaure 을 순회하기

int paper[130][130] = {0};

pair<int,int> pap(int n,int x,int y){  

    if(n==1){
        if(paper[x][y] == 1) return {0,1};
        else return {1,0};
    }

    int papcount = 0;

    for(int i = 0;i<n;i++){
        for(int j = 0; j < n; j++){
            if (paper[i+x][j+y]==1) papcount++;
            else papcount--;
        }
    }
        if(papcount == n*n) return {0,1}; //블루에 하나
        else if(papcount == -n*n) return {1,0}; //화이트에 ㅏㅎ나.


        return pap(n/2,x,y) + pap(n/2,x,y+n/2) + pap(n/2,x+n/2,y+n/2) + pap(n/2,x+n/2,y);
}

int main(){
    int N;
    cin >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin >> paper[i][j];
        }
    }

    pair<int,int> result = pap(N,0,0); 
    cout << result.first << "\n"<<result.second;
    



    return 0;
}