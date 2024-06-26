#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    int P;
    cin>>P;

    for(int i = 0; i < P; i++){
        int N,M;
        cin >> N >> M;

        queue<int> Q;
        vector<pair<int,char>> A(10010);
        bool V[10010] = {0};
        

        Q.push(N);
        V[N] = 1;

        while(!Q.empty()){
            int cur = Q.front(); Q.pop();

            if(cur == M){
                break;
            }
            int temp;


            int D =(2*cur)%10000;
            if(!V[D]){
            V[D] = 1;
            A[D] = {cur,'D'};
            Q.push(D);
            }


            temp = cur/1000;
            int L = (cur%1000)*10 + temp;
            if(!V[L]) {
            V[L] = 1;
            A[L] = {cur,'L'};
            Q.push(L);
            }

            temp = cur%10;
            int R = (cur/10)+temp*1000;
            if(!V[R]){
            
            V[R] = 1;
            A[R] = {cur,'R'};
            Q.push(R);
            }

            
            int S = (cur-1); 
            if (S==-1) S = 9999;
            if(!V[S]){
            V[S]= 1;
            A[S] = {cur,'S'};
            Q.push(S);
            }
        }
        
        vector<char> result;
        
        
        while(1){

            result.push_back(A[M].second);
            M = A[M].first;
            if(M==N) break;
        }
        reverse(result.begin(), result.end());
        for(auto x:result){
            cout << x;
        }
        cout<<"\n";
    }
    
    return 0;
}