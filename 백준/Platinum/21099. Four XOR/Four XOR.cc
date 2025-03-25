#include <bits/stdc++.h>
using namespace std;

/*
n 개의 수가 있을 때, 2개를 집어서 XOR 이 같은 경우를 보면 됨. 
10^5 까지 주어져있으니, 대충 XOR한 값이 2^17 개 정도 나올 수 있음.
그러면 XOR 한 값이 2^17 개가 중복되지 않게 주어진다면, 그 다음은 무조건 중복될 수 밖에 없다.(비둘기집 원리)

그러므로 nC2 >= 2^17 되는 지점을 찾으면 한 510? 그정도임
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    
    if(n > 510) {
        cout << "Yes";
        return 0;
    }
    else { 
        for(int i = 0; i < n; i++) cin >> arr[i];
        for(int a = 0; a < n-3; a++) {
            for(int b = a+1; b < n-2; b++) {
                for(int c = b+1; c < n-1; c++) {
                    for(int d = c+1; d < n; d++) {
                        if((arr[a]^arr[b]^arr[c]^arr[d]) == 0) {
                            cout << "Yes";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "No";
}