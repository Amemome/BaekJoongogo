#include <iostream>
#include <vector>


using namespace std;

int main(){ 


    int N,target;
    cin >> N >> target;
    vector<long long> v(N,0);
    long long low = 0,mid = 0,top = 0;

    for(int i = 0;i<N;i++){
        cin >> v[i];
        if (v[i]>top){
            top = v[i];
        }
    }


               //높이가 높으면 자르는 크기가 작아집니다. 그래서 배열을 봤을 떄, 자르는 높이가 작을떄 높이가 높을 것. 0 , 그리고 그거면...
    while (low<=top) {

        mid = (low + top)/2;
        
        long long logs = 0;
        for (int i = 0; i < N; i++){
            long long cost = v[i]-mid;
            if (cost > 0) logs += cost;
        }
        if ((logs-target)>= 0 &&(logs-target) < 0) {
            cout << low;
            return 0;
        }
        if (logs >= target) {
            low = mid + 1;
        } else if (logs < target) {
            top = mid - 1;
        }
        
    }



    cout << top;

        
    return 0;
}



