#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


/*
그런디 수를 0으로 넘겨줄 수 있는 방법의 갯수.
1011 -> 0111 
1111 -> 0011
1000 -> 0100

1011
1000
0011 인데요

1111 -> 0011 으로 만들기.

1100 result 랑



0이 아닌 님수는 0으로 만들 수 있음. 님수를 0으로 만들어야지.
각 이랑 xor 한 값 ? 이 원본보다 작음 ?
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int cnt = 0;
    int arr[n+1];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int result = 0;
    for(int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    

    for(int i = 0; i < n; i++) {
        int xx = result ^ arr[i];
        if(arr[i] > xx) cnt++;
    }    

    cout << cnt;

    

}