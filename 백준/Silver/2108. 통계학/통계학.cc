#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

//최빈값 출력을 어떻게 할 것인가? 정렳하면 1 2 3 4 4 5 6 6 6 이런식.
//map 자료형을 쓰면 key 로 정렬을 해준다고 하네요 그래서 map 에다가 때려박을것.

int main(){ 

    int N;
    cin >> N;
    
    map<int,int> arr; //key 는 실제 입력된 값, value 는 출현한 횟수를 나타낸다.
    vector<int> tosort;
  
    int sum = 0;
    for(int i = 0; i < N; i++){

        int n;
        cin >>n;
        
        sum += n;
        arr[n]++;
        
        tosort.push_back(n);
    }

    sum = round(sum / (float) N);

    int maxfre = 0, frequent;
    


    for (auto x: arr){
        if (x.second > maxfre) maxfre = x.second;
    }
    int ccount = 0;
    for (auto x : arr){
        if (x.second == maxfre) {
            ccount +=1;
            if (ccount == 1){
                frequent = x.first;
            } else if (ccount == 2) {
                frequent = x.first;
                break;
            }
        }

    }   


    sort(tosort.begin(),tosort.end());
    


    cout << sum << "\n" << tosort[N/2] << "\n" << frequent << "\n" <<  tosort.back()-tosort.front();

    return 0;
}



