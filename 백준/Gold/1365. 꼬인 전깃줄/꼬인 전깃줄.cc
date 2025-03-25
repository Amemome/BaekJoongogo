<<<<<<< HEAD
#include <bits/stdc++.h>
#define ref(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;    cin >> N;
    vector<int> arr(N,0);
    vector<int> dp;
    for(int i = 0;i<N; i++) cin >> arr[i];
    vector<int> index;
    for(auto x : arr){ //dp에서 x가처음나오는위치 이분탐색
        auto it = lower_bound(dp.begin(),dp.end(),x);
        index.push_back(it - dp.begin());//x가부분순열에서
        if(it == dp.end()) {//       위치하는 인덱스(길이-1)
            dp.push_back(x);//만약에dp끝이면pushback.
        } else{            //아니면 바꾸기.
            *it = x;
        }
    }
    cout << N - dp.size();
=======
#include <bits/stdc++.h>
#define ref(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;    cin >> N;
    vector<int> arr(N,0);
    vector<int> dp;
    for(int i = 0;i<N; i++) cin >> arr[i];
    vector<int> index;
    for(auto x : arr){ //dp에서 x가처음나오는위치 이분탐색
        auto it = lower_bound(dp.begin(),dp.end(),x);
        index.push_back(it - dp.begin());//x가부분순열에서
        if(it == dp.end()) {//       위치하는 인덱스(길이-1)
            dp.push_back(x);//만약에dp끝이면pushback.
        } else{            //아니면 바꾸기.
            *it = x;
        }
    }
    cout << N - dp.size();
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}