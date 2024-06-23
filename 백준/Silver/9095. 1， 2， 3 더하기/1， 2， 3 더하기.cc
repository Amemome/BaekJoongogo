#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

//점화식어케함
//1을 더하고 2를 더하고 3을 더해야되는데.. 현재 i 에 있는 방법은, i-1 에서 1+를 붙인거, i-2 에서 2+를 붙인거 i-3 에서 3+
//를 붙인거라서 이전꺼그냥더하면됨
int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int N;
    cin >> N;  

    vector<int> nums;
    int max=0;

    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        nums.push_back(num);
        max = (max>nums[i])? max:nums[i];
    }




    long long dist[11]; //회수의 최솟값을 구함. 배열에는 최솟값을 넣음.
    dist[1] = 1;
    dist[2] = 2;
    dist[3] = 4;
    
    for(int i = 4; i <= max;i++){
        dist[i] = dist[i-1] + dist[i-2] + dist[i-3];
    }

    for(auto X:nums){
        cout << dist[X] << "\n";
    }
    return 0;
}


