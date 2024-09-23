#include<iostream>
#include<vector>

using namespace std;

/*
kx 가 있겠죠. k 의 범위 안에 들어오는지 보면 됨.
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;

    vector<long long> arr(n+1,0);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    long long k;
    cin >> k;


    for (long long i = 1; i <= n; i++) {
        if(arr[i] == k*i) {
            cout << 'T';
            return 0;
        }
    }

    for(long long i = 1; i < n; i++){
        if(arr[i] >= k*i && arr[i+1] <= k*(i+1)) {
            cout << 'T';
            return 0;
        }
    }
    cout << 'F';

    return 0;
}